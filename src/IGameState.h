// Interface to define Game States
#ifndef IGAMESTATE_H
#define IGAMESTATE_H

class IGameState
{
public:
    // Destructor
    virtual ~IGameState() { };

    // What happens when the state is initialized
    virtual void Initialize() = 0;

    // What happens when the state is no longer needed
    virtual void Cleanup() = 0;

    // What happens when the game pauses
    virtual void Pause() = 0;

    // What happens after a pause
    virtual void Resume() = 0;

    // What happens in response to events
    virtual bool HandleEvents() = 0;

    // Called once per frame. Update game logic.
    virtual bool Update() = 0;

    // Called once per frame. Draw to the screen.
    virtual void Render() = 0;
};
#endif