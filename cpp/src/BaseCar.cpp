#include "BaseCar.h"

BaseCar::BaseCar(float width,float length)
{
    m_Width = width;
    m_Length = length;
    m_Body = 0;
}

BaseCar::~BaseCar()
{
}

b2Vec2 BaseCar::GetPosition()
{
    // ASSERT (m_Body!=0)
    return m_Body->GetPosition();
}

float BaseCar::GetAngle()
{
    return m_Body->GetAngle();
}