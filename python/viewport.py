# this is a viewport class

import pygame as pg
import math

# viewport constants
WINSIZE = [1000,1000]   # size in pixels
WINCENTER = [500,500]   # center in pixels
WINSCALE = WINSIZE[0]/70      # viewport scale (pixels per meter)


class Sprite:
    def __init__(self,w_m,h_m,filename):
        self.width = w_m;
        self.height = h_m;
        self.surface = pg.image.load(filename)

    def draw_centered(self,surface,x,y,angle,scale):
        # x,y in pixels
        # angle in degrees
        # scale in pixels per meter

        # compute dimensions, in PIXELS
        w = self.width * scale
        h = self.height * scale
        scaled_image = pg.transform.smoothscale(self.surface,(w,h))
        rotated_image = pg.transform.rotate(scaled_image,angle*180/math.pi)
        surface.blit(rotated_image,[x-rotated_image.get_width()/2,y-rotated_image.get_height()/2])

class Viewport: 
    def __init__(self,windowtitle):
        # create our screen surface
        self.screen = pg.display.set_mode(WINSIZE)
        pg.display.set_caption(windowtitle)

        # pygame clock
        self.clock = pg.time.Clock()

    def clear(self):
        self.screen.fill((0,0,0))

    def update(self,ticks):
        done = False
        pg.display.update()
        for e in pg.event.get():
            if e.type == pg.QUIT or (e.type == pg.KEYUP and e.key == pg.K_ESCAPE):
                done = True
                break
        self.clock.tick(ticks)

        return done # return True if window closed or ESC depressed

    def draw_sprite(self,sprite,x_m,y_m,angle):
        sprite.draw_centered(self.screen,WINCENTER[0]+x_m*WINSCALE,WINCENTER[1]-y_m*WINSCALE,angle,WINSCALE)
        
