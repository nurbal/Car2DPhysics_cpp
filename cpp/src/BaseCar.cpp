#include "BaseCar.h"

BaseCar::BaseCar()
{
    m_Body = 0;
}

b2Vec2 BaseCar::GetPosition()
{
    // ASSERT (m_Body!=0)
    return m_Body->GetPosition();
}