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
        this->isActive = false;
        this->start = NULL;
        this->end = NULL;
        return false;
    }
    return true;
}

void Well::Draw()
{
    /*
    GLfloat vertices[722];
    float cnst = 3.1415927/360;
    for(int i = 0; i < 722; i+=2){
        vertices[i]   = this->position.X() + cos(cnst * i) * this->size;
        vertices[i+1] = this->position.Y() + sin(cnst * i) * this->size;
    }
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 361);
    */

    GLfloat square[] = { this->position.X() - this->size, this->position.Y() - this->size, 0.0f, /* Top left */
                           this->position.X() - this->size, this->position.Y() + this->size, 0.0f, /* Bottom left */
                           this->position.X() + this->size, this->position.Y() + this->size, 0.0f, /* Bottom right */
                           this->position.X() + this->size, this->position.Y() - this->size, 0.0f }; /* Top right */

    GLubyte indices[] = {0, 1, 2,
                         3, 1, 2};

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, square);
    glDrawElements(GL_QUADS, 6, GL_UNSIGNED_BYTE, indices);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

}