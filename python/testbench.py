# test bench for car2dphysics cpp library
# uses pygame to output graphics & input (keyboard and/or analog joystick)

import os
import sys

dir_path = os.path.dirname(os.path.realpath(__file__))
sandbox_path=dir_path+'/../build'
sys.path.append(sandbox_path)

import car2dphysics as cp
import pygame as pg


CAR_WIDTH = 2
CAR_LENGTH = 4

import viewport as vp


def main():
    # init pygame
    pg.init()

    # init viewport
    viewport = vp.Viewport("Car2DPhysics TestBench")

    # create and get car visual objects
    res_dir = os.path.split(os.path.abspath(__file__))[0]+"/resources/"
    freecar_sprite = vp.Sprite(CAR_WIDTH,CAR_LENGTH,res_dir+"freecar.png")
    trajectorycar_sprite = vp.Sprite(CAR_WIDTH,CAR_LENGTH,res_dir+"trajectorycar.png")

    # create car2dphysics environment
    cp.init()
    circuit = cp.BenchmarkCircuit8()
    freecar = circuit.GetFreeCar()
    trajectrorycars = circuit.GetTrajectoryCars()

    # for car in trajectrorycars:
    #     print (car.GetTrajectory())

    # TODO create road borders

    # simulation loop
    done = False
    tc = 0;
    while not done:
        # joystick / keyboard input
        steer = 0
        throttle = 0
        brake = 0
        keys = pg.key.get_pressed()
        if keys[pg.K_LEFT]:
            steer -= 1;
        if keys[pg.K_RIGHT]:
            steer += 1;
        if keys[pg.K_UP]:
            throttle += 1;
        if keys[pg.K_DOWN]:
            throttle -= 1;
        if keys[pg.K_SPACE]:
            brake = 1;
        if pg.joystick.get_count()>0:
            j = pg.joystick.Joystick(0)
            steer+=j.get_axis(0)
            throttle-=j.get_axis(1)

        # update physics simulation
        circuit.Step(0.02)

        # print(str(freecar))
        freecar.Turn(steer)
        freecar.Throttle(throttle)
        freecar.Brake(brake)
        # print(freecar.GetPosition())


        # render...
        viewport.clear()

        (x,y,angle) = freecar.GetPosition()
        viewport.draw_sprite(freecar_sprite,x,y,angle)

        for car in trajectrorycars:
            (x,y,angle) = car.GetPosition()
            viewport.draw_sprite(trajectorycar_sprite,x,y,angle)


        # viewport.draw_sprite(freecar_sprite,-5,0,-angle)

        done = viewport.update(50)
        tc += 0.02  # 20ms = 50fps


if __name__ == "__main__":
    main()

