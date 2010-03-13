// Class to handle all higher-level game functions. 
// i.e. Running the main loop and drawing to the screen (for now.
// Eventually, rendering will be separated out to it's own module.)

#ifndef GAMEAPP_H
#define GAMEAPP_H

#include <string>
using namespace std;

#include "Mass.h"
#include "StateManager.h"
#include "GameplayState.h"

class GameApp
{
public:
    // Constructor
	GameApp(int window_width, int window_height, bool isFullScreen,
			string title)
	: width(window_width),
	  height(window_height),
	  is_fullscreen(isFullScreen),
	  window_title(title)
	{
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
	
	// Updates the game state
	void Update();

    StateManager stateManager;

	int width;
	int height;
	bool is_fullscreen;
	string window_title;
};
#endif