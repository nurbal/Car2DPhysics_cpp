#include "FreeCar.h"
#include "defines.h"
#include <stdlib.h>
#include <iostream>
#include <string>

FreeCar::FreeCar(b2World *world, float spawnDistance, float maxDistance) : BaseCar(CAR_WIDTH,CAR_LENGTH)
{
    m_World = world;

    // temporarily set a maximum distance to trigger a respawn at (0,0)
    m_SpawnDistance =           spawnDistance;
    m_MaxDistance =             maxDistance;

    // vehicle characteristics
    m_MaxSpeed =                FREECAR_MAXSPEED;
    m_MaxReverseSpeed =         FREECAR_MAXREVERSESPEED;
    m_MaxThrottleAccel =        FREECAR_MAXTHROTTLEACCEL;
    m_MaxThrottleReverseAccel = FREECAR_MAXTHROTTLEREVERSEACCEL;
    m_MaxBrakeAccel =           FREECAR_MAXBRAKEACCEL;
    m_MinTurnRadius =           FREECAR_MINTURNRADIUS;

    // vehicle status
    m_ThrottleAccel = 0.f;
    m_BrakeAccel = 0.f;
    m_Steering = 0.f;
    m_Speed = 0.f;
    
    // create the body of the car...
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody; // speed set by user, moved by solver
    m_Body = m_World->CreateBody(&bodyDef);
    b2PolygonShape shape; 
    shape.SetAsBox(m_Width/2,m_Length/2); 
    m_Body->CreateFixture(&shape,0.f);

    // position the body
    Respawn();
    
}

FreeCar::~FreeCar()
{
    // TODO
}

void FreeCar::Respawn()
{
    float x = m_SpawnDistance * (-1.f+2.f*(((float)rand()) / (float)RAND_MAX));
    float y = m_SpawnDistance * (-1.f+2.f*(((float)rand()) / (float)RAND_MAX));
    b2Vec2 position(x,y);
    m_Body->SetTransform(position,0.f);
}

void FreeCar::Throttle(float value)
{
    if (value>0)
        m_ThrottleAccel = m_MaxThrottleAccel * value;
    else
        m_ThrottleAccel = m_MaxThrottleReverseAccel * value;
    m_BrakeAccel = 0.f;     // could be matter of design discussion
}

void FreeCar::Brake(float value)
{
    if (fabsf(value)<0.001) return;
    m_ThrottleAccel = 0;    // could be matter of design discussion
    m_BrakeAccel = m_MaxBrakeAccel * value;

}

void FreeCar::Turn(float value)
{
    m_Steering = value;
}

void FreeCar::Step(float dt)
{
    // Respawn if too far from origin ?
    if (m_Body->GetPosition().Length() > m_MaxDistance)
        Respawn();

    // Compute accelerations
    float speedTarget = 0.f;
    float acceleration = 0.f;
    if (m_ThrottleAccel > 0.f)
    {
        // accel forward
        if (m_ThrottleAccel>m_BrakeAccel)
        {
            // accelerate
            speedTarget = m_MaxSpeed;
            acceleration = m_ThrottleAccel - m_BrakeAccel;
        }
        else
        {
            // brake
            speedTarget = 0.f;
            acceleration = m_BrakeAccel - m_ThrottleAccel;
        }
    }
    else
    {
        // accel backward
        if (m_ThrottleAccel<-m_BrakeAccel)
        {
            // accelerate
            speedTarget = m_MaxReverseSpeed;
            acceleration = -m_ThrottleAccel - m_BrakeAccel;
        }
        else
        {
            // brake
            speedTarget = 0.f;
            acceleration = m_BrakeAccel + m_ThrottleAccel;
        }
    }

    // Compute Speed
    float deltaV = acceleration * dt;
    if (m_Speed<speedTarget)
        // accelerate forward 
        m_Speed = fminf(m_Speed+deltaV,speedTarget);   
    else
        // accelerate backward
        m_Speed = fmaxf(m_Speed-deltaV,speedTarget);

    // Move (done outside box2D solver, because of turning ray...)
    float c = cosf(m_Body->GetAngle());
    float s = sinf(m_Body->GetAngle());
    b2Vec2 forward(-s,c);   // Y axis=forward, X=right
    b2Vec2 right(c,s);

    float dP = m_Speed*dt;    // abscisse curviligne
    float dx = 0; float dy = dP;    // default forward values
    float alpha = 0.f;  // angle change
    if (fabs(m_Steering)>0.01)
    {
        // we are turning
        float ray = 1.f/m_Steering * m_MinTurnRadius;
        alpha = dP/ray;
        float dx = -ray*(1.f-cosf(alpha));
        float dy = ray*sinf(alpha);
    }
    b2Vec2 newPos(m_Body->GetPosition());
    right *= dx;
    forward *= dy;
    newPos += right;
    newPos += forward;
    float newAngle = m_Body->GetAngle() - alpha;
    m_Body->SetTransform(newPos,newAngle);
}


