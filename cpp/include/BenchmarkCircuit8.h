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
        std::list<TrajectoryCar*> GetTrajectoryCars();

    protected:
        std::list<Trajectory*> m_Trajectories;
        std::list<BaseCar*> m_Cars;
        std::list<TrajectoryCar*> m_TrajectoryCars;
        FreeCar* m_FreeCar;
};
