#include "GameplayState.h"

#include <string>
using namespace std;

// Globals for the shader.
// NEEDS TO BE REFACTORED WHEN SHADER MANAGER
// IS WRITTEN.
GLuint vShader, fShader, program;

void GameplayState::Initialize()
{
    /* Test data */
    this->AddMass(Vector2D(300.0f, 400.0f), 500.0f, 20.0f);
    this->AddMass(Vector2D(400.0f, 300.0f), 40000.0f, 20.0f);
    this->AddMass(Vector2D(500.0f, 200.0f), 500.0f, 10.0f);


    /* Compile and link shaders. */
    SetupShaders();
    
    /* Enable sounds */
    SetupSound();

    /* Start sound */
    BeginSound();
}

/**
 * Adds a gravity well to the system if the current number of wells <= the maximum
 * number of wells allowed. If not, does nothing.
 * Parameters:
 *  - Vector2D position: A vector representing the position at which the well should exist.
 *  - double lifespan: The number of seconds the well should exist.
 */
void GameplayState::AddWell(Vector2D position, double lifespan)
{
    if(wells.size() >= kMaxWells) return;
    wells.push_back(WellPtr(new Well(position, 30000.0f, lifespan))); 
}

/**
 * Adds a mass to the system if the current number of masses <= the maximum number
 * of masses allowed. If not, does nothing.
 *
 * Parameters:
 *  - Vector2D position: A vector representing the position at which the mass starts.
 *  - float mass: The mass value of the new mass
 *  - float size: The visible size of the mass
 */
void GameplayState::AddMass(Vector2D position, float mass, float size)
{
    if(masses.size() >= kMaxMasses) return;
    masses.push_back(MassPtr(new Mass(position, Vector2D(0.0f,0.0f), mass, size, 200, 150, 20)));
    this->totalMass += mass;
}


/**
 * Check the resultof FMOD functions to determine success. If the result is FMOD_OK, does nothing.
 * If it isn't, the result error is printed.
 * 
 * Parameters:
 *  - FMOD_RESULT result: The result to be checked. FMOD functions generally return these
 */
void GameplayState::FMODCheckError(FMOD_RESULT result)
{
    if(result != FMOD_OK)
    {
        printf("FMOD Error (%d) %s\n", result, FMOD_ErrorString(result));
    }
}

/**
 * Initialize sound system and checks for errors
 */
void GameplayState::SetupSound()
{
    /* Create the audio system */
    FMODCheckError(FMOD::System_Create(&system));

    /* Initialize the audio system */
    FMODCheckError(system->init(1, FMOD_INIT_NORMAL, 0));



}

/**
 * Begins playing the gameplay sound
 */
void GameplayState::BeginSound()
{
    /* Create a streaming resource to an audio file. (Saves memory over decoding an entire file at once) */
    FMODCheckError(system->createStream("../media/multitouch01.mp3", FMOD_HARDWARE | FMOD_LOOP_NORMAL | FMOD_2D, 0, &sound));

    /* Play the sound, looping */
    FMODCheckError(system->playSound(FMOD_CHANNEL_FREE, sound, false, &channel));
}

void GameplayState::SetupShaders()
{
    GLint success;
    const GLchar* vsStringPtr[1];
    const GLchar* fsStringPtr[1];

    GLchar* vsString = textFileRead("shaders/minimal.vert");
    GLchar* fsString = textFileRead("shaders/minimal.frag");


    if (!GLEE_VERSION_2_0 && (!GLEE_ARB_vertex_shader || 
                          !GLEE_ARB_fragment_shader || 
                          !GLEE_ARB_shader_objects || 
                          !GLEE_ARB_shading_language_100))
    {
        /* Can't initialize OpenGL Extensions */
        exit(1);
    }

    /* Create shader objects and specify shader contents */
    vShader = glCreateShader(GL_VERTEX_SHADER);
    fShader = glCreateShader(GL_FRAGMENT_SHADER);

    vsStringPtr[0] = vsString;
    glShaderSource(vShader, 1, vsStringPtr, NULL);

    fsStringPtr[0] = fsString;
    glShaderSource(fShader, 1, fsStringPtr, NULL);

    /* Compile and check for errors */
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




void GameplayState::Cleanup()
{

    glDeleteShader(vShader);
    glDeleteShader(fShader);
    glDeleteProgram(program);
    FMODCheckError(sound->release());
    FMODCheckError(system->close());
    FMODCheckError(system->release());
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
            if(event.button.button == SDL_BUTTON_LEFT)
            {
                this->AddWell(Vector2D((float)event.button.x, (float)event.button.y), 5);
            }
            else if(event.button.button == SDL_BUTTON_RIGHT)
            {
                this->AddMass(Vector2D((float)event.button.x, (float)event.button.y), 50.0f, 2.0f);
            }
            
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
	
    glScalef(this->zoomFactor, this->zoomFactor, this->zoomFactor);
    
    glValidateProgram(program);


    for(vector<MassPtr>::iterator it = this->masses.begin(); it != this->masses.end(); ++it)
    {
        
        (*it)->Draw();
    }

    for(vector<WellPtr>::iterator it = this->wells.begin(); it != this->wells.end(); ++it)
    {
        (*it)->Draw();
    }

    SDL_GL_SwapBuffers();
}

bool GameplayState::Update()
{
    if(!this->HandleEvents()) return false;

    for(vector<WellPtr>::iterator it = this->wells.begin(); it != this->wells.end(); ++it)
    {
        if(!(*it)->CheckTime())
        {
            wells.erase(it);
            break;
        }
    }

    for(vector<MassPtr>::iterator it = this->masses.begin(); it != this->masses.end(); ++it)
    {
        (*it)->Update();
        
        for(vector<WellPtr>::iterator wellIt = this->wells.begin(); wellIt != this->wells.end(); ++wellIt)
        {
            (*it)->ApplyGravityFrom(*(*wellIt).get(), 1.0f);
        }
    }

    return true;
}

void GameplayState::Resume()
{
}