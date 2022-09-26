#include "TrajectoryCar.h"
#include "defines.h"
#include <cmath>

TrajectoryCar::TrajectoryCar(b2World *world, Trajectory *trajectory, float speed, float initialtrip) : BaseCar(CAR_WIDTH,CAR_LENGTH)
{
    m_Trajectory = trajectory;
    m_Speed = speed;
    m_Trip = initialtrip;
    m_World = world;

    // create the body of the car...
    b2BodyDef bodyDef;
    bodyDef.type = b2_kinematicBody; // speed set by user, moved by solver
    m_Body = m_World->CreateBody(&bodyDef);
    b2PolygonShape shape; 
    shape.SetAsBox(m_Width/2,m_Length/2); 
    m_Body->CreateFixture(&shape,0.f);

    // position the body
    float angle = m_Trajectory->GetAngle(m_Trip);
    b2Vec2 position;
    m_Trajectory->GetPosition(m_Trip,position);
    m_Body->SetTransform(position,angle);
}

TrajectoryCar::~TrajectoryCar()
{
    // we only own the box2d body, all other variables are managed somewhere else...
}

void TrajectoryCar::Step(float dt)
{
    // update trip (=abscissa along the trajectory)
    m_Trip += dt*m_Speed;
    while(m_Trip >= m_Trajectory->GetLength())
        m_Trip -= m_Trajectory->GetLength();
    // set transform of body
    float angle = m_Trajectory->GetAngle(m_Trip);
    b2Vec2 position;
    m_Trajectory->GetPosition(m_Trip,position);
    m_Body->SetTransform(position,angle);
    // set velocity
    b2Vec2 velocity;
    m_Trajectory->GetDirection(m_Trip,velocity);
    velocity*=m_Speed;
    m_Body->SetLinearVelocity(velocity);
}
