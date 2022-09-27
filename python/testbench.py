# test bench for car2dphysics cpp library
# uses pygame to output graphics & input (keyboard and/or analog joystick)

import os
import sys

dir_path = os.path.dirname(os.path.realpath(__file__))
sandbox_path=dir_path+'/../build'
sys.path.append(sandbox_path)

import car2dphysics as cp

WINSIZE = [1000,1000]
WINCENTER = [500,500]
WINSCALE = [20,20]  # viewport dimensions (in m)

import viewport as vp


def main():

    # init pygame window
    viewport = vp.Viewport("Car2DPhysics TestBench")

    # create car2dphysics environment

    # simulation loop
    done = False
    while not done:
        done = viewport.update(50)


if __name__ == "__main__":
    main()

