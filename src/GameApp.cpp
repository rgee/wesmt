#ifdef WIN32
    #include <windows.h>
#endif

#ifdef __APPLE__
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
#else
    #include <GL/gl.h>
    #include <GL/glu.h>
#endif

#include <iostream>
#include <sstream>
#include <vector>
#include "SDL/SDL.h"
#include "GameApp.h"

using namespace std;


void GameApp::Initialize()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		 fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
	}
	
	if(this->is_fullscreen)
	{
		SDL_SetVideoMode(this->width, this->height, 0, SDL_DOUBLEBUF | SDL_FULLSCREEN | SDL_OPENGL);
	}
	else
	{
		SDL_SetVideoMode(this->width, this->height, 0, SDL_DOUBLEBUF | SDL_OPENGL);
	}
	SDL_WM_SetCaption("Wesleyan Multitouch Particles", NULL);
	
	puts("Initializing OpenGL");
	
    glViewport(0, 0, this->width, this->height);
	
	// Clear the screen to black for each draw call
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
	
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	
	// Enable smooth shading
	glShadeModel(GL_SMOOTH);
	
	// Reset the projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    glOrtho(0, this->width, this->height, 0, -1, 1);
	
	//gluPerspective(45.0f, ((GLfloat)width / (GLfloat)height), 0.1f, 1000.0f);
	
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void GameApp::Quit()
{
    SDL_Quit();
}

void GameApp::BeginMainLoop()
{
    this->stateManager = StateManager(new GameplayState());

    int frames = 0, update;
    float fps;
    update = SDL_GetTicks();

	while(1)
	{
        
        if(!this->stateManager.GetCurrentState()->Update()) break;
        this->stateManager.GetCurrentState()->Render();

        if((SDL_GetTicks() - update) > 1000 )
        {
            /*
            stringstream caption;
            fps = frames / (SDL_GetTicks() - update) * 1000;

            caption << fps;
            SDL_WM_SetCaption(caption.str().c_str(), NULL);
            */

            update = SDL_GetTicks();
            frames = 0;
        }
        frames++;
        SDL_Delay(10);
	}
    this->Quit();
}

int main(int argc, char **argv)
{  
	GameApp app = GameApp(800, 600, false, "Wesleyan Multitouch Particles");
	return 1;
}
