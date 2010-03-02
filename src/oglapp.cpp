#include <GL/gl.h>
#include <GL/glu.h>
#include "SDL/SDL.h"
#include "math.h"
#include <vector>
#include "vector2D.h"
using namespace std;



int radius = 5;
float rotation = 0.0f;

void Init(int width, int height)
{
	glViewport(0, 0, width, height);
	
	// Clear the screen to black for each draw call
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
	
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	
	// Enable smooth shading
	glShadeModel(GL_SMOOTH);
	
	// Reset the projection matric
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluPerspective(45.0f, ((GLfloat)width / (GLfloat)height), 0.1f, 1000.0f);
	
	glMatrixMode(GL_MODELVIEW);
}

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	glTranslatef(-1.5f, 1.0f, -6.0f);
	glRotatef(rotation, 0.0f, 0.0f, 1.0f);
	
	// Draw a triangle
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
			glVertex2f(1.0f + sin(angle) * 0.1,
						1.0f + cos(angle) * 0.1);
		}
	glEnd();
	
	SDL_GL_SwapBuffers();
}

void HandleInput()
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

int main(int argc, char **argv)
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		 fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
	}
	 
	SDL_SetVideoMode(800, 600, 0, SDL_OPENGL);
	
	SDL_WM_SetCaption("Wesleyan Multitouch Particles", NULL);
	
	Init(800, 600);
	
	Vector2D vec(5.0, 6.0);
	
	
	while(1)
	{
		rotation += 1.0f;
		Draw();
		HandleInput();
	}
	return 1;
}
