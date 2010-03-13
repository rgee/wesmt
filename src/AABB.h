// Axis-Aligned Bounding Box for collision detection
#ifndef AABB_H
#define AABB_H

#include "Vector2D.h"

class AABB
{
public:
    AABB(Vector2D cent, float radius)
        : center(cent),
          rx(radius),
          ry(radius)
    {};
    AABB() {};
    virtual ~AABB() {};

    // Checks to see if AABB "other" intersects with this AABB
    bool Intersects(const AABB& other) const;

    // Get the center point
    Vector2D GetCenter() const { return center; }

    // Set the center point
    void SetCenter(const Vector2D newCenter) { center = newCenter; }

    // Get the radius
    float GetRadius() const { return rx; }

    // Set the radius
    void SetRadius(const float newRadius) { ry = rx = newRadius; }

    // Recompute the AABB at a new center
    void Recompute(Vector2D center);


private:
    // We represent AABBs as a center and half width extents along the 
    // x and y axis. This is a slightly more convenient solution as opposed
    // to using two Vector2Ds for the min and max corner points because
    // after a translation, we will only have to update three floats instead
    // of six.

    // Center point
    Vector2D center;
    
    // Length of the bounding box from the center point to its far edge
    // along the X axis
    float rx;

    // Length of the bounding box from the center point to its far edge
    // along the Y axis
    float ry;
};
#endif