#include "MainMenu.h"


void MainMenu::PlayGame()
{
}

void MainMenu::QuitGame()
{
}

void MainMenu::OptionsMenu()
{
}

void MainMenu::Initialize()
{

    this->menuItems.push_back("Play Game");
}

void MainMenu::Cleanup()
{
}

void MainMenu::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
    SDL_GL_SwapBuffers();
}

bool MainMenu::HandleEvents()
{
    SDL_Event event;
	
	while(SDL_PollEvent(&event))
	{
        switch(event.type)
        {
        case SDL_QUIT:
            return false;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)       
            {
                case SDLK_ESCAPE: 
                    return false;
                    break;
                case SDLK_KP_ENTER:
                    this->ConfirmCurrentSelection();
                    break;
                case SDLK_UP:
                    if(this->currentSelectedItem >= (int)this->menuItems.size())
                    {
                        this->currentSelectedItem = (int)this->menuItems.size();
                    }
                    else
                    {
                        this->ConfirmCurrentSelection();
                        this->currentSelectedItem++;
                    }
                    break;
                case SDLK_DOWN:
                    if(this->currentSelectedItem <= 0)
                    {
                        this->currentSelectedItem = 0;
                    }
                    else
                    {
                        this->currentSelectedItem--;
                    }
                    break;
            }
        }
    }
    return true;
}

void MainMenu::ConfirmCurrentSelection()
{
    printf("OUTPUT: %s ",this->menuItems[20]);
}

bool MainMenu::Update()
{

    if(!this->HandleEvents()) return false;
    return true;
}

void MainMenu::Pause()
{
}

void MainMenu::Resume()
{
}
