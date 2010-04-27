// Implements the IGameState interface

#ifndef GAMEPLAYSTATE_H
#define GAMEPLAYSTATE_H


#include <vector>
using namespace std;

#include "../libs/GLee.h"




#ifdef WIN32
    #include <windows.h>

    /* Keeping this inside the conditional until we get someone with 
       a non-Windows machine to install fmod and see where the headers
       end up.

       For now, Windows devs just point visual studio's directories to
       the location where you installed the SDK
    */
    #include "fmod.hpp"
    #include "fmod_errors.h"
#endif

#ifdef __APPLE__
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
#else
    #include <GL/gl.h>
    #include <GL/glu.h>
#endif



#include "SDL/SDL.h"

#include "Mass.h"
#include "IGameState.h"
#include "TextFileUtil.h"

// Max particles to be displayed on screen.
const int kMaxMasses = 400;

class GameplayState : public IGameState
{
public:
    GameplayState() : masses(400), numMasses(0), zoomFactor(1.0f), totalMass(0.0f) { };
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
    // Add a new mass to the system.
    void AddMass(Vector2D position, float mass, float radius);

    // Translate window coordinates to openGL coordinates
    Vector2D GetOGLCoordinates(float x, float y);

    // Loads and compiles shaders
    void SetupShaders();

    // Initializes and starts the audio system.
    void SetupSound();

    // Helper function to check the result code of FMOD function calls
    void FMODCheckError(FMOD_RESULT result);

    // Masses
    vector<Mass> masses;

    // Current number of masses
    int numMasses;

    // Zoom factor for the perspective view
    float zoomFactor;
    
    // The sum of the mass values of all masses on screen
    float totalMass;

    // Is the mouse being pressed?
    bool mouseDown;

    // FMOD sound system
    FMOD::System  *system;

    // FMOD sound object
    FMOD::Sound   *sound;

    // FMOD channel object
    FMOD::Channel *channel;

};

#endif