#pragme once


#include "BaseCar.h"

class MovingCar : public BaseCar
{
    public:
        MovingCar();
        virtual ~MovingCar();

        virtual void Step(float dt);

};
