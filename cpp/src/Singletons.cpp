#include "Singletons.h"

static b2World *s_b2World = 0;
b2World* Getb2World()
{
    if (!s_b2World) 
    {
        b2Vec2 gravity;
        gravity.Set(0.0f, 0.0f);
        s_b2World = new b2World(gravity);
    }
    return s_b2World;
}