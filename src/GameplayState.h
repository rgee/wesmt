// Implements the IGameState interface

#ifndef GAMEPLAYSTATE_H
#define GAMEPLAYSTATE_H

#include <vector>
using namespace std;

#include "Mass.h"

class GameplayState : public IGameState
{
public:
    virtual GameplayState();
    virtual ~GameplayState();

    // IGameState interface
    virtual void Initialize();
    virtual void Cleanup();
    virtual void Pause();
    virtual void Resume();
    virtual void HandleEvents();
    virtual void Update();
    virtual void Render();
private:
    vector<Mass> masses;
}

#endif