from automata.automata import Automata
import time
from matplotlib import pyplot as plt
from matplotlib import animation
import numpy as np
ca = Automata(2, 200, 2, 1, 6152, 2, .75, 200)
ca.initializeTwoDimensionalCells()

anim = np.asarray(ca.generateTwoDimensionalSequence_2State())

temp_im = np.zeros([len(anim[0]),len(anim[0])])

def init():
    global fig, ax, im
    fig = plt.figure()
    ax = plt.axes()
    im = ax.imshow(temp_im,interpolation='nearest',animated=True,vmin=-0.2,vmax=0.2)
    im.set_data(temp_im)
    return

def animate(i):
    temp_im = anim[i]
    im.set_data(temp_im)
    return
init()
animate = animation.FuncAnimation(fig, animate,frames=len(anim))
animate.save('anim22.mp4',extra_args=['-vcodec','libx264'])
fig.show() 
for i in range(25):
    ca.updateTwoDimensionalCells()
    time.sleep(.1)
    #ca.displayTwoDimensionalCells_2State()
