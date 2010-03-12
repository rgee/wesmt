#include "GameplayState.h"


void GameplayState::GameplayState() : masses(3)
{

}

void GameplayState::Initialize()
{
        this->masses[0].SetPosition(Vector2D(1.0f, 1.0f));
        this->masses[0].SetRadius(10.0f);

        this->masses[1].SetPosition(Vector2D(0.5f, 0.5f));
        this->masses[1].SetRadius(20.0f);

        this->masses[2].SetPosition(Vector2D(1.0f, -1.0f));
        this->masses[2].SetRadius(15.0f);
}

void GameplayState::Cleanup()
{
}

void GameplayState::HandleEvents()
{
}

void GameplayState::Pause()
{
}

void GameplayState::Render()
{
    for(vector<Mass>::iterator it = this->masses.begin(); it != this->masses.end(); ++it)
    {
        it->Draw();
    }
}

void GameplayState::Update()
{
    for(vector<Mass>::iterator it = this->masses.begin(); it != this->masses.end(); ++it)
    {
        it->Update();
    }
}

void GameplayState::HandleEvents()
{
}

void GameplayState::Resume()
{
}