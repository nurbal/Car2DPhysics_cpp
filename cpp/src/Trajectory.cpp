#include "Trajectory.h"


Trajectory::Trajectory(std::list<b2Vec2>* waypoints)
{
    
}

Trajectory::~Trajectory()
{

}

float Trajectory::GetLength()
{
    return 0.f;
}

int Trajectory::GetNbSegments()
{
    return m_Segments.size();
}

void Trajectory::GetPosition(float abscissa, b2Vec2 *position)
{
    
}

float Trajectory::GetAngle(float abscissa)
{
    return 0.f;
}
        
// typedef struct 
// {
//     b2Vec2 P1;          // starting point
//     b2Vec2 P2;          // end point
//     float length;       // segment lenght
//     float P1Abscissa;   // segment start abscissa
// } Segment;

// std::list<Segment*> m_Segments;  

Trajectory::Segment* Trajectory::GetSegment(float abscissa)
{
    return nullptr;
}
