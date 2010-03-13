// Axis-Aligned Bounding Box for collision detection

#include "Vector2D.h"

class AABB
{
public:
    AABB(Vector2D cent, float xExtent, float yExtent)
        : center(cent),
          rx(xExtent),
          ry(yExtent)
    {};
    AABB() {};
    virtual ~AABB() {};

    bool Intersects(AABB other) const;
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
}