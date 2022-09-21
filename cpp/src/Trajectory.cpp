#include "Trajectory.h"

#include <iterator>
#include <math.h>

Trajectory::Trajectory(std::list<b2Vec2>* waypoints)
{
    if (waypoints->size()>=2)
    {
        std::list<b2Vec2>::iterator it=waypoints->begin();
        b2Vec2 P1=*it;
        float abscissa = 0.f;
        it++;
        for (; it!=waypoints->end(); it++)
        {
            b2Vec2 P2 = *it;
            Segment* s = new Segment;
            s->P1 = P1;
            s->P2 = P2;
            b2Vec2 D = P2 - P1;
            s->length = D.Normalize();
            s->N = D;
            s->abscissa = abscissa;
            m_Segments.push_back(s);
            abscissa += s->length;
            P1 = P2;
        }

    }
}

Trajectory::~Trajectory()
{
    // delete all segments in memory
    while (!m_Segments.empty())
    {
        delete m_Segments.back();
        m_Segments.pop_back();
    }
}

float Trajectory::GetLength()
{
    if (!m_Segments.empty())
    {
        Segment *s = m_Segments.back();
        return s->length + s->abscissa;
    }
    return 0.f;
}

// int Trajectory::GetNbSegments()
// {
//     return m_Segments.size();
// }

void Trajectory::GetPosition(float abscissa, b2Vec2 &position)
{
    Segment *s = GetSegment(abscissa);
    position = s->N;
    position *= (abscissa-s->abscissa);
    position += s->P1;
}

float Trajectory::GetAngle(float abscissa)
{
    Segment *s = GetSegment(abscissa);
    if (!s) 
        return 0.f;
    float angle = acosf(s->N.x);
    if (s->N.y<0)
        angle = -angle;
    return angle;
}

Trajectory::Segment* Trajectory::GetSegment(float abscissa)
{
    for (std::list<Segment*>::iterator it = m_Segments.begin(); it!=m_Segments.end(); it++)
    {
        Segment *s = *it;
        if (s->abscissa + s->length > abscissa)
            return s;
    }
    return nullptr;
}
