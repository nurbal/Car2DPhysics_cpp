#pragma once


#include "BaseCar.h"
#include "Trajectory.h"


class TrajectoryCar : public BaseCar
{
    public:
        TrajectoryCar(b2World *world, Trajectory *trajectory, float speed, float initialtrip=0.f);
        virtual ~TrajectoryCar();

        virtual void Step(float dt);

    protected:
        Trajectory* m_Trajectory;
        float       m_Speed;
        float       m_Trip;
        b2World*    m_World;
};
