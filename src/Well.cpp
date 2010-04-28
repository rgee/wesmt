#include "Well.h"

void Well::ToggleActive()
{
    isActive = !isActive;

    if(isActive)
    {
        // Grab the creation time
        time(&start);
    }
}

bool Well::CheckTime()
{
    // Grab the current time and compare it to
    // the creation time
    time(&end);
    if(difftime(end, start) >= lifespan)
    {
        this->ToggleActive();
        return false;
    }
    return true;
}