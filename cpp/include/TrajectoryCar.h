#pragma once


#include "BaseCar.h"

class TrajectoryCar : public BaseCar
{
    public:
        TrajectoryCar();
        virtual ~TrajectoryCar();

        virtual void Step(float dt);

};
