#include "AABB.h"
#include "math.h"

bool AABB::Intersects(const AABB& other) const
{
    if(abs(this->center.X() - other.GetCenter().X()) > (this->rx + other.GetRadius())) return false;
    if(abs(this->center.Y() - other.GetCenter().Y()) > (this->ry + other.GetRadius())) return false;

    return true;
}