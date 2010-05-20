/**
 * This is where ALL gameplay related work happens. Implements the IGameState interface.
 *
 * TODO:
 *  - Maintain a map from levels to resources. Probably std::Map<string, string> or something.
 *    This will allow us to easily specify what resources (audio, textures, etc) need to be loaded
 *    for each level
 */

#ifndef GAMEPLAYSTATE_H
#define GAMEPLAYSTATE_H

#include <vector>
using namespace std;

#include "../libs/GLee.h"

#include <boost/shared_ptr.hpp>


#ifdef WIN32
    #include <windows.h>
    #include "fmod.hpp"
    #include "fmod_errors.h"
#endif

#ifdef __APPLE__
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
    #include "/Developer/FMOD Programmers API Mac/api/inc/fmod.hpp"
    #include "/Developer/FMOD Programmers API Mac/api/inc/fmod_errors.h"
#else
    #include <GL/gl.h>
    #include <GL/glu.h>
#endif



#include "SDL/SDL.h"

class Well;
class Vector2D;

#include "IGameState.h"
#include "TextFileUtil.h"
#include "Mass.h"

/* Typedef to ease the use of smart pointers for our game objects */

/* Devs new to smart pointers, please read up on boost::shared_ptr specifically
   at www.boost.org or in general in either Effective C++ or on wikipedia. In short,
   these are reference-counted pointers that ensure that the destructor of each
   Mass or Well is called at the instant there exist zero references to it. Makes
   sure we don't leak memory in most cases. To see the value of this, you need to know
   about heap-allocated objects vs stack-allocated objects and the nature of scoping in C++. */
typedef boost::shared_ptr<Mass> MassPtr;
typedef boost::shared_ptr<Well> WellPtr;

/* Max particles to be displayed on screen. */
const int kMaxMasses = 40000;

/* The amount of gravity wells that can be active at once. */
const int kMaxWells = 50;

class GameplayState : public IGameState
{
public:
    GameplayState() : zoomFactor(1.0f), totalMass(0.0f) { };
    virtual ~GameplayState() {};

    /* IGameState interface */
    virtual void Initialize();
    virtual void Cleanup();
    virtual void Pause();
    virtual void Resume();
    virtual bool HandleEvents();
    virtual bool Update();
    virtual void Render();


private:
    /* Add a new graivty well */
    void AddWell(Vector2D position, double lifespan);

    /* Add a new mass to the system. */
    void AddMass(Vector2D position, float mass, float radius);

    /* Add a new mass to the system, specifying color */
    void AddMass(Vector2D position, float mass, float radius, float color);

    /* Translate window coordinates to openGL coordinates */
    Vector2D GetOGLCoordinates(float x, float y);

    /* Load and compiles shaders */
    void SetupShaders();

    /* Initializes the audio system. */
    void SetupSound();

    /* Begins playing the gameplay music */
    void BeginSound();

    /* Helper function to check the result code of FMOD function calls */
    void FMODCheckError(FMOD_RESULT result);

    /* Gravity wells */
    vector<WellPtr> wells;

    /* Masses */
    vector<MassPtr> masses;

    /* Zoom factor for the perspective view */
    float zoomFactor;
    
    /* The sum of the mass values of all masses on screen */
    float totalMass;

    /* Is the mouse being pressed? */
    bool mouseDown;

    /* FMOD sound system */
    FMOD::System  *system;

    /* FMOD sound object */
    FMOD::Sound   *sound;

    /* FMOD channel object */
    FMOD::Channel *channel;

};

#endif