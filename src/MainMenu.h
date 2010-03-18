#ifndef MAINMENU_H
#define MAINMENU_H

#include <string>
#include <map>
#include <vector>

using namespace std;

#include "IGameState.h"


class MainMenu : public IGameState
{
public:

    // Typedef for MainMenu member function pointers
    typedef void (MainMenu::*Callback)();
    
    // Typedef for a map from strings to MainMenu member function pointers
    typedef map<string, Callback> CBTable;

    MainMenu() { selectedItem = this->callbacks.find("Play Game"); };
    virtual ~MainMenu();

    // What happens when a user selects the play game option
    void PlayGame();

    // What happens when a user selects the quit game option
    void QuitGame();

    // What happens when a user selects the Options option
    void OptionsMenu();

    // Select the next item in the menu
    void SelectNext() { selectedItem++; };

    // Select the previous item in the menu
    void SelectPrevious() { selectedItem--;};
    
    // Confirm a selection
    void Confirm() {(*selectedItem).second(); }

    // IGameState interface
    virtual void Initialize();
    virtual void Cleanup();
    virtual void Pause();
    virtual void Resume();
    virtual bool HandleEvents();
    virtual bool Update();
    virtual void Render();

private:
    // A map from strings to member function pointers
    CBTable callbacks;

    // Iterator over the map of callbacks
    CBTable::const_iterator selectedItem;
};

#endif