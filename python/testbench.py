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

CAR_WIDTH = 2
CAR_LENGTH = 5

import viewport as vp


def main():

    # init viewport
    viewport = vp.Viewport("Car2DPhysics TestBench")

    # create and get car visual objects
    main_dir = os.path.split(os.path.abspath(__file__))[0]
    freecar_sprite = vp.Sprite(CAR_WIDTH,CAR_LENGTH,main_dir+"/data/freecar.png")
    trajectorycar_sprite = vp.Sprite(CAR_WIDTH,CAR_LENGTH,main_dir+"/data/trajectorycar.png")

    # create car2dphysics environment

    # TODO create freecar
    # TODO create trajectory cars
    # TODO create road borders

    # simulation loop
    done = False
    while not done:

        # joystick / keyboard input




        done = viewport.update(50)


if __name__ == "__main__":
    main()

