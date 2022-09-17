#pragme once

#include "BaseCar.h"

class FreeCar : public BaseCar
{
    public:
        FreeCar();
        virtual ~FreeCar();

        virtual void Step(float dt);

        void Throttle(float value);
        void Brake(float value);
        void Turn(float value);


};
