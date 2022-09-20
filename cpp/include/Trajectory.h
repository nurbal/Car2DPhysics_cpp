#pragma once

#include <box2d/box2d.h>
#include <list>

class Trajectory
{
    public:
        Trajectory(std::list<b2Vec2>* waypoints);
        virtual ~Trajectory();

        float GetLength();
        int GetNbSegments();

        void GetPosition(float abscissa, b2Vec2 *position);
        float GetAngle(float abscissa);
        
    protected:
        typedef struct 
        {
            b2Vec2 P1;          // starting point
            b2Vec2 P2;          // end point
            float length;       // segment lenght
            float P1Abscissa;   // segment start abscissa
        } Segment;

        std::list<Segment*> m_Segments;  
        Segment* GetSegment(float abscissa);         

};
