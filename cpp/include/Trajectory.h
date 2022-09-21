#pragma once

#include <box2d/box2d.h>
#include <list>
#include <string>

class Trajectory
{
    public:
        Trajectory(std::list<b2Vec2>* waypoints);
        Trajectory(std::list<float>* waypoints);
        virtual ~Trajectory();

        float GetLength();
        // int GetNbSegments();

        void GetPosition(float abscissa, b2Vec2 &position);
        float GetAngle(float abscissa);

        std::string Repr();
        
    protected:
        void Init(std::list<b2Vec2>* waypoints);

        typedef struct 
        {
            b2Vec2 P1;          // starting point
            b2Vec2 P2;          // end point
            b2Vec2 N;           // unit vector
            float length;       // segment lenght
            float abscissa;   // segment start abscissa
        } Segment;

        std::list<Segment*> m_Segments;  
        Segment* GetSegment(float abscissa);         

};
