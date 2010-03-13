// Class to manage the organization of game states
#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <vector>

// Forward declaration instead of an include here since
// we only use pointers to IGameStates
class IGameState;

using namespace std;

class StateManager
{
public:
    StateManager();
    virtual ~StateManager();

    // Returns a pointer to the current game state
    IGameState* GetCurrentState() { return states.back();}

    // Remove the current state and add a new one in its place
    void ChangeState(IGameState* state);

    // Add a new current state
    void PushState(IGameState* state);

    // Move back to the previous state
    void PopState();

    // Cleanup and remove all states
    void Clear();
private:
    vector<IGameState*> states;
};
#endif