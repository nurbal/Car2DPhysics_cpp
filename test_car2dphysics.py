import os
import sys
import numpy as np

dir_path = os.path.dirname(os.path.realpath(__file__))
sandbox_path=dir_path+'/build'
sys.path.append(sandbox_path)

import car2dphysics as cp

waypoints=[1.0,2.0,3.0,4.0,5,6]
print (waypoints)
t = cp.Trajectory(waypoints)

print (str(t))