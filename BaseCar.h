#pragma once

#include <box2d/box2d.h>

class BaseCar
{
    public:
        BaseCar();
        virtual ~BaseCar();

        virtual void Step(float dt) = 0;

        b2Vec2 GetPosition();

    protected:
        b2Body *m_Body;
};