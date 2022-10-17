#pragma once

#include "BaseCar.h"

class FreeCar : public BaseCar
{
    public:
        FreeCar(b2World *world, float spawnDistance, float maxDistance);
        virtual ~FreeCar();

        virtual void Step(float dt);

        void Throttle(float value);
        void Brake(float value);
        void Turn(float value);

    protected:
        b2World*    m_World;

        float m_SpawnDistance;
        float m_MaxDistance;
        float m_MaxSpeed;
        float m_MaxReverseSpeed;
        float m_MaxThrottleAccel;
        float m_MaxThrottleReverseAccel;
        float m_MaxBrakeAccel;
        float m_MinTurnRadius;
        float m_SideSpeedDamping;
        float m_AngularDamping;

        float m_ThrottleAccel;
        float m_BrakeAccel;
        float m_Steering;
//        float m_Speed;

        void Respawn();
};
