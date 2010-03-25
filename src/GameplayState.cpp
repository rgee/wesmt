#include "GameplayState.h"

#include <string>
using namespace std;

// Globals for the shader.
// NEEDS TO BE REFACTORED WHEN SHADER MANAGER
// IS WRITTEN.
GLuint vShader, fShader, program;

void GameplayState::Initialize()
{
    this->AddMass(Vector2D(300.0f, 400.0f), 500.0f, 20.0f);
    this->AddMass(Vector2D(400.0f, 300.0f), 40000.0f, 20.0f);
    this->AddMass(Vector2D(500.0f, 200.0f), 500.0f, 10.0f);

    this->masses[0].SetColor(255, 0, 55);

    this->masses[1].SetColor(13, 255, 0);

    this->masses[2].SetColor(0, 38, 255);

    // Compile and link shaders.
    SetupShaders();

}

void GameplayState::SetupShaders()
{
    GLint success;
    const GLchar* vsStringPtr[1];
    const GLchar* fsStringPtr[1];

        GLchar vsString[] = 
        "void main(void)\n"
        "{\n"
        "    // This is our Hello World vertex shader\n"
        "    // notice how comments are preceded by '//'\n"
        "\n"
        "    // normal MVP transform\n"
        "    vec4 clipCoord = gl_ModelViewProjectionMatrix * gl_Vertex;\n"
        "    gl_Position = clipCoord;\n"
        "\n"
        "    // Copy the primary color\n"
        "    gl_FrontColor = gl_Color;\n"
        "\n"
        "    // Calculate NDC\n"
        "    vec4 ndc = vec4(clipCoord.xyz, 0) / clipCoord.w;\n"
        "\n"
        "    // Map from [-1,1] to [0,1] before outputting\n"
        "    gl_FrontSecondaryColor = (ndc * 0.5) + 0.5;\n"
        "}\n";

    GLchar fsString[] = 
        "void main(void)\n"
        "{\n"
        "    // Mix primary and secondary colors, 50/50\n"
        "    vec4 temp = mix(gl_Color, vec4(vec3(gl_SecondaryColor), 1.0), 0.3);\n"
        "\n"
        "    gl_FragColor = temp * 0.3;\n"
        "}\n";

        if (!GLEE_VERSION_2_0 && (!GLEE_ARB_vertex_shader || 
                              !GLEE_ARB_fragment_shader || 
                              !GLEE_ARB_shader_objects || 
                              !GLEE_ARB_shading_language_100))
        {
            // Should quit
        }
    
        // Create shader objects and specify shader contents
        vShader = glCreateShader(GL_VERTEX_SHADER);
        fShader = glCreateShader(GL_FRAGMENT_SHADER);

        vsStringPtr[0] = vsString;
        glShaderSource(vShader, 1, vsStringPtr, NULL);

        fsStringPtr[0] = fsString;
        glShaderSource(fShader, 1, fsStringPtr, NULL);

        // Compile and check for errors
        glCompileShader(vShader);
        glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            // Should print errors
        }

        glCompileShader(fShader);
        glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            // Should print errors
        }

        // Create program object
        program = glCreateProgram();
        glAttachShader(program, vShader);
        glAttachShader(program, fShader);

        // Link shaders

        glLinkProgram(program);
        glUseProgram(program);
}

void GameplayState::AddMass(Vector2D position, float mass, float radius)
{
    if(this->numMasses == kMaxMasses) return;

    
    this->masses[numMasses].SetPosition(position);
    this->masses[numMasses].SetRadius(radius);
    this->masses[numMasses].SetMass(mass);
    this->masses[numMasses].SetExists(true);
    this->totalMass += mass;

    this->numMasses++;
}

void GameplayState::Cleanup()
{
    glDeleteShader(vShader);
    glDeleteShader(fShader);
    glDeleteProgram(program);
}




// This might be very messy without a 3d vector class. We need to write one, but I 
// recommend keeping it separate from the 3d vector class because 99% of the time
// we know the z component of what we're using and it's always the same value. There's
// no reason to use a 3-dimensional vector there and store an extra float value that may
// never be used and may never change.
// 
// However, here a 3d vector would be useful because we actually are dealing with depth to
// intersect with the plane on the Y axis...
//
// CURRENT FUNCTION STATUS: BROKEN
Vector2D GameplayState::GetOGLCoordinates(float x, float y)
{
    /*
    GLint viewport[4];
    GLdouble modelView[16];
    GLdouble projection[16];
    GLfloat winX, winY;
    GLfloat newDepth;
    GLdouble x1, y1, z1, x2, y2, z2;

    glGetDoublev(GL_MODELVIEW_MATRIX, modelView);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glGetIntegerv(GL_VIEWPORT, viewport);

    winX = (float)x;
    winY = (float)viewport[3] - y;


    //glReadPixels(winX, winY, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &newDepth);


    // We unProject twice with z = 1 and z = 0 then intersect the line segment created by these
    // two points with the Y-plane. The point of intersection is our position.

    // Near plane
    gluUnProject(winX, winY,  0, modelView, projection, viewport, &x1, &y1, &z1);

    // Far plane
    gluUnProject(winX, winY,  1, modelView, projection, viewport, &x2, &y2, &z2);



    return Vector2D((x2 - x1) * (z2 / z1) , (y2 - y1) * (z2/z1));
    */

    return Vector2D(0, 0);
}

bool GameplayState::HandleEvents()
{
    SDL_Event event;
	
	while(SDL_PollEvent(&event))
	{
        switch(event.type)
        {
        case SDL_QUIT:
            return false;
        case SDL_MOUSEBUTTONDOWN:
            this->AddMass(Vector2D((float)event.button.x, (float)event.button.y), 50.0f, 2.0f);
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)       
            {
                case SDLK_DOWN:
                    if((this->zoomFactor - 0.1f) <= 0)
                    {
                        this->zoomFactor = 0;
                    }
                    else
                    {
                        this->zoomFactor -= 0.1f;
                    }
                    break;
                case SDLK_UP:
                        this->zoomFactor += 0.1f;
                    break;
                case SDLK_ESCAPE: 
                    return false;
                    break;
            }
        }
    }
    return true;
}



void GameplayState::Pause()
{
}

void GameplayState::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
    //glTranslatef(0.0, 0.0, -6.0f);
    glScalef(this->zoomFactor, this->zoomFactor, this->zoomFactor);
    

    // Validate shaders
    glValidateProgram(program);


    for(vector<Mass>::iterator it = this->masses.begin(); it != this->masses.end(); ++it)
    {
        if(!it->GetExists()) continue;
        it->Draw();
    }

    SDL_GL_SwapBuffers();
}

bool GameplayState::Update()
{
    //SDL_PumpEvents();
    if(!this->HandleEvents()) return false;

    for(vector<Mass>::iterator it = this->masses.begin(); it != this->masses.end(); ++it)
    {
        if(!it->GetExists()) continue;
        it->Update();
        
        
        for(vector<Mass>::iterator itB = this->masses.begin(); itB != this->masses.end(); ++itB){
            if(&it != &itB) 
                it->ApplyGravityFrom(*itB, 1.0f);
        }
        
    }

    return true;
}

void GameplayState::Resume()
{
}