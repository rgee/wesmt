#if defined (__WIN32__)    
    #include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include "SDL/SDL.h"
#include "GameApp.h"
#include "Particle.h"


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
	
	gluPerspective(45.0f, ((GLfloat)width / (GLfloat)height), 0.1f, 1000.0f);
	
	glMatrixMode(GL_MODELVIEW);
}

void GameApp::HandleInput()
{
	SDL_Event event;
	
	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
		{
			SDL_Quit();
		}
		if(event.type == SDL_KEYDOWN)
		{
			if(event.key.keysym.sym == SDLK_ESCAPE)
			{
				SDL_Quit();
			}
		}
	}
}

void GameApp::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	glTranslatef(-1.5f, 1.0f, -6.0f);
	
	
	glRotatef(rotation, 0.0f, 0.0f, 1.0f);
	
	/*
	glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f( 0.0f, 1.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f( 1.0f,-1.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-1.0f,-1.0f, 0.0f);
	glEnd();
	*/
	
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(1.0f, 1.0f);
		for(int angle = 0; angle < 360; angle++)
		{
			glVertex2f(1.0f + sin(double(angle)) * 0.1,
						1.0f + cos(double(angle)) * 0.1);
		}
	glEnd();
	
	
	SDL_GL_SwapBuffers();
}

void GameApp::Update()
{
	rotation += 0.1f;
	this->HandleInput();
}

void GameApp::BeginMainLoop()
{
	while(1)
	{
		this->Update();
		this->Draw();
	}
}

int main(int argc, char **argv)
{
	GameApp app = GameApp(800, 600, false, "Wesleyan Multitouch Particles");
	return 1;
}
