#pragma once

#include <box2d/box2d.h>

class BaseCar
{
    public:
        BaseCar(float width,float length);
        virtual ~BaseCar();

        virtual void Step(float dt) = 0;

        b2Vec2 GetPosition();
        float GetAngle();

    protected:
        b2Body *m_Body;
        float m_Width;
        float m_Length;
};