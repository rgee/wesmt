#ifndef MAINMENU_H
#define MAINMENU_H

#include <string>
#include <vector>

#include "../libs/GLee.h"

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

#include "SDL/SDL.h"

#include "IGameState.h"

using namespace std;

class MainMenu : public IGameState
{
public:

    MainMenu() : currentSelectedItem(0), menuItems(20) { };

    virtual ~MainMenu() {};

    // What happens when a user selects the play game option
    void PlayGame();

    // What happens when a user selects the quit game option
    void QuitGame();

    // What happens when a user selects the Options option
    void OptionsMenu();

    void ConfirmCurrentSelection();

    // IGameState interface
    virtual void Initialize();
    virtual void Cleanup();
    virtual void Pause();
    virtual void Resume();
    virtual bool HandleEvents();
    virtual bool Update();
    virtual void Render();

private:
    int currentSelectedItem;
    vector<string> menuItems;
};

#endif