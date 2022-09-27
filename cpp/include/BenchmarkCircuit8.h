#pragma once

#include "Trajectory.h"
#include "FreeCar.h"
#include "TrajectoryCar.h"

class BenchmarkCircuit8
{
    public:
        BenchmarkCircuit8();
        virtual ~BenchmarkCircuit8();

        void Step(float dt);

        FreeCar* GetFreeCar();

    protected:
        std::list<Trajectory*> m_Trajectories;
        std::list<BaseCar*> m_Cars;
        FreeCar* m_FreeCar;
};
