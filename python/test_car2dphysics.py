import os
import sys

dir_path = os.path.dirname(os.path.realpath(__file__))
sandbox_path=dir_path+'/../build'
sys.path.append(sandbox_path)

import car2dphysics as cp

waypoints=[0,0,1,0,2,1]
print (waypoints)
t = cp.Trajectory(waypoints)

print (str(t))

print (str(t.GetLength()))
