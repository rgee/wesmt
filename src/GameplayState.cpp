#include "GameplayState.h"

#include <string>
using namespace std;

void GameplayState::Initialize()
{
    this->masses[0].SetPosition(Vector2D(0.0f, 0.0f));
    this->masses[0].SetRadius(10.0f);
    this->masses[0].SetMass(100.0f);
    this->numMasses++;

    this->masses[1].SetPosition(Vector2D(1.0f, 1.0f));
    this->masses[1].SetRadius(20.0f);
    this->masses[1].SetMass(100.0f);
    this->numMasses++;
    
    this->masses[2].SetPosition(Vector2D(-1.0f, -1.0f));
    this->masses[2].SetRadius(15.0f);
    this->masses[2].SetMass(100.0f);
    this->numMasses++;
    
}

void GameplayState::Cleanup()
{
}

Vector2D GameplayState::GetOGLCoordinates(float x, float y)
{
    GLint viewport[4];
    GLdouble modelView[16];
    GLdouble projection[16];
    GLfloat winX, winY;
    GLfloat newDepth;
    GLdouble posX, posY, posZ;

    glGetDoublev(GL_MODELVIEW_MATRIX, modelView);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glGetIntegerv(GL_VIEWPORT, viewport);

    winX = (float)x;
    winY = (float)viewport[3] - y;


    glReadPixels(winX, winY, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &newDepth);

    gluUnProject(winX, y,  (double)newDepth, modelView, projection, viewport, &posX, &posY, &posZ);

    return Vector2D(posX, posY);
}

bool GameplayState::HandleEvents()
{
    SDL_Event event;
	
	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
		{
			return false;
		}
		if(event.type == SDL_KEYDOWN)
		{
			if(event.key.keysym.sym == SDLK_ESCAPE)
			{
				return false;
			}
		}
        if(event.type == SDL_MOUSEBUTTONDOWN)
        {
            if(this->numMasses < kMaxMasses)
            {
                OutputDebugString(L"Adding a new mass\n");
                this->masses[this->numMasses + 1].SetPosition(this->GetOGLCoordinates((float)event.button.x, (float)event.button.y));
                this->masses[this->numMasses + 1].SetRadius(10.0f);
                this->masses[this->numMasses + 1].SetMass(1000.0f);
                this->numMasses += 1;
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
	
    glTranslatef(0.0, 0.0, -6.0f);

    for(vector<Mass>::iterator it = this->masses.begin(); it != this->masses.end(); ++it)
    {
        it->Draw();
    }

    SDL_GL_SwapBuffers();
}

bool GameplayState::Update()
{
    if(!this->HandleEvents()) return false;

    for(vector<Mass>::iterator it = this->masses.begin(); it != this->masses.end(); ++it)
    {
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