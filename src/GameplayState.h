// Implements the IGameState interface

#ifndef GAMEPLAYSTATE_H
#define GAMEPLAYSTATE_H


#include <vector>
using namespace std;

#include "Mass.h"
#include "IGameState.h"

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

// Max particles to be displayed on screen.
const int kMaxMasses = 100;

class GameplayState : public IGameState
{
public:
    GameplayState() : masses(100), numMasses(0) { };
    virtual ~GameplayState() {};

    // IGameState interface
    virtual void Initialize();
    virtual void Cleanup();
    virtual void Pause();
    virtual void Resume();
    virtual bool HandleEvents();
    virtual bool Update();
    virtual void Render();


private:
    // Translate window coordinates to openGL coordinates
    Vector2D GetOGLCoordinates(float x, float y);
    vector<Mass> masses;
    int numMasses;
};

#endif