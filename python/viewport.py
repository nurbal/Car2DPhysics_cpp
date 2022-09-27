# this is a viewport class

import pygame as pg

# viewport constants
WINSIZE = [1000,1000]   # size in pixels
WINCENTER = [500,500]   # center in pixels
WINSCALE = [20,20]      # viewport dimensions (in m)


class Viewport: 
    def __init__(self,windowtitle):
        # create our screen surface
        pg.init()
        self.screen = pg.display.set_mode(WINSIZE)
        pg.display.set_caption(windowtitle)

        # pygame clock
        self.clock = pg.time.Clock()

        pass

    def update(self,ticks):
        done = False
        pg.display.update()
        for e in pg.event.get():
            if e.type == pg.QUIT or (e.type == pg.KEYUP and e.key == pg.K_ESCAPE):
                done = True
                break
        self.clock.tick(ticks)

        return done # return True if window closed or ESC depressed