#include "BenchmarkCircuit8.h"
#include "Trajectory.h"
#include "Singletons.h"
#include <box2d/box2d.h>


BenchmarkCircuit8::BenchmarkCircuit8()
{
    // utility vectors
    b2Vec2 N(0,1);
    b2Vec2 S(0,-1);
    b2Vec2 E(1,0);
    b2Vec2 W(-1,0);
    b2Vec2 _NE = N + E;
    b2Vec2 _NW = N + W;
    b2Vec2 _SE = S + E;
    b2Vec2 _SW = S + W;

    // 8-shape
    //       d---e
    //       |   |
    //   a---o---f
    //   |   |
    //   b---c

    float l = 30; // half road length
    float w = 9;  // half-road width
    b2Vec2 _a(-l,0);
    b2Vec2 _b(-l,-l);
    b2Vec2 _c(0,-l);
    b2Vec2 _d(0,l);
    b2Vec2 _e(l,l);
    b2Vec2 _f(l,0);

    float coefs[3] = {w*0.25f, w*0.75f, w*1.f};
    b2Vec2 NE[3],NW[3],SE[3],SW[3];
    for (int i=0; i<2; i++)
    {
        NE[i] = _NE; NE[i]*=coefs[i];
        SE[i] = _SE; SE[i]*=coefs[i];
        NW[i] = _NW; NW[i]*=coefs[i];
        SW[i] = _SW; SW[i]*=coefs[i];
    }


    // street borders and trajectory points
    // a0-------------------street edge 
    // |  a1----------------lane 1 
    // |  |  a2-------------lane 2  
    // |  |  |  a...........center-line
    // |  |  |  :  a3-------lane 3 
    // |  |  |  :  |  a4----lane 4 
    // |  |  |  :  |  |  a5-street edge 
    // |  |  |  :  |  |  | 

    b2Vec2 a[6] = {_a+NW[2] , _a+NW[1] ,  _a+NW[0] , _a+SE[0] , _a+SE[1] , _a+SE[2]};
    b2Vec2 b[6] = {_b+SW[2] , _b+SW[1] ,  _b+SW[0] , _b+NE[0] , _b+NE[1] , _b+NE[2]};
    b2Vec2 c[6] = {_c+SE[2] , _c+SE[1] ,  _c+SE[0] , _c+NW[0] , _c+NW[1] , _c+NW[2]};
    b2Vec2 d[6] = {_d+SE[2] , _d+SE[1] ,  _d+SE[0] , _d+NW[0] , _d+NW[1] , _d+NW[2]};
    b2Vec2 e[6] = {_e+SW[2] , _e+SW[1] ,  _e+SW[0] , _e+NE[0] , _e+NE[1] , _e+NE[2]};
    b2Vec2 f[6] = {_f+NW[2] , _f+NW[1] ,  _f+NW[0] , _f+SE[0] , _f+SE[1] , _f+SE[2]};

    // trajectories of 2x2 lanes
    std::list<b2Vec2> traj1 = {a[1],b[1],c[1],d[1],e[1],f[1],a[1]};
    std::list<b2Vec2> traj2 = {a[2],b[2],c[2],d[2],e[2],f[2],a[2]};
    std::list<b2Vec2> traj3 = {a[3],f[3],e[3],d[3],c[3],b[3],a[3]};
    std::list<b2Vec2> traj4 = {a[4],f[4],e[4],d[4],c[4],b[4],a[4]};
    m_Trajectories.push_back(new Trajectory(&traj1));
    m_Trajectories.push_back(new Trajectory(&traj2));
    m_Trajectories.push_back(new Trajectory(&traj3));
    m_Trajectories.push_back(new Trajectory(&traj4));

    // # street borders
    // edges = [
    //     [ [a[0],b[0]], [b[0],c[0]], [c[0],SE*w], [SE*w,f[5]], [f[5],e[5]], [e[5],d[5]], [d[5],NW*w], [NW*w,a[0]], ],
    //     [ [a[5],b[5]], [b[5],c[5]], [c[5],SW*w], [SW*w,a[5]], ],
    //     [ [d[0],e[0]], [e[0],f[0]], [f[0],NE*w], [NE*w,d[0]], ],
    // ]

    // for edge in edges:
    //     for segment in edge:
    //         self.world.CreateBody(shapes=b2EdgeShape(vertices=segment))

    // # cars !
    // self.cars = []
    // nbCarsPerTrack = 10

    // # automatic cars (waypoints)
    // for lane in range(4):
    //     speed = random.random()*20+10
    //     for c in range(nbCarsPerTrack):
    //         initialTrip = c*trajectories[lane].length/nbCarsPerTrack
    //         self.cars.append( WaypointsCar(world=self.world,trajectory=trajectories[lane],speed=speed,initialtrip=initialTrip) )

    // free car
    m_FreeCar = new FreeCar(Getb2World(),w/4,l*2);
    m_Cars.push_back(m_FreeCar);

}

BenchmarkCircuit8::~BenchmarkCircuit8()
{

}

void BenchmarkCircuit8::Step(float dt)
{
    for (std::list<BaseCar*>::iterator it = m_Cars.begin(); it!=m_Cars.end(); it++)
        (*it)->Step(dt);
}

FreeCar* BenchmarkCircuit8::GetFreeCar()
{
    return m_FreeCar;
}