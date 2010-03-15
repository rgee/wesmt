#include "StateManager.h"

void StateManager::PopState()
{
    if(!states.empty())
    {
        states.back()->Cleanup();
        states.pop_back();
        states.back()->Resume();
    }
}


void StateManager::PushState(IGameState *state)
{
    if(!states.empty())
    {
        states.back()->Pause();
    }

    states.push_back(state);
    states.back()->Initialize();
}

void StateManager::ChangeState(IGameState *state)
{
    if(!states.empty())
    {
        states.back()->Cleanup();
        states.pop_back();
    }

    states.push_back(state);
    states.back()->Initialize();
}

void StateManager::Clear()
{
    while(!states.empty())
    {
        states.back()->Cleanup();
        states.pop_back();
    }
}