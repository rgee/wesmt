// Class to handle all higher-level game functions. 
// i.e. Running the main loop and drawing to the screen (for now.
// Eventually, rendering will be separated out to it's own module.)

#ifndef GAMEAPP_H
#define GAMEAPP_H

#include <string>
using namespace std;

#include "Mass.h"

class GameApp
{
public:
    // Constructor
	GameApp(int window_width, int window_height, bool isFullScreen,
			string title)
	: width(window_width),
	  height(window_height),
	  is_fullscreen(isFullScreen),
	  window_title(title),
	  rotation(0.0f),
      particles(3)
	{
        this->particles[0].SetPosition(Vector2D(1.0f, 1.0f));
        this->particles[0].SetRadius(10.0f);

        this->particles[1].SetPosition(Vector2D(0.5f, 0.5f));
        this->particles[1].SetRadius(20.0f);

        this->particles[2].SetPosition(Vector2D(1.0f, -1.0f));
        this->particles[2].SetRadius(15.0f);


		this->Initialize();
		this->BeginMainLoop();
	}

	// Begins the main loop
	void BeginMainLoop();

private:
	// Initializes the game application
	void Initialize();

	// Draws the current frame to the screen
	void Draw();
	
	// Handles input events
	void HandleInput();
	
	// Updates the game state
	void Update();


	int width;
	int height;
	bool is_fullscreen;
	string window_title;
	float rotation;
    vector<Mass> particles;
};
#endif