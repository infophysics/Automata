from automata.automata import Automata, Cell, Conway
import time
from matplotlib import pyplot as plt
from matplotlib import animation
import numpy as np

ca = Conway(10,1,.37,10)
ca.initializeTwoDimensionalEmptyCells()
ca.placeObject("xq4_27deee6", 0, 0, True)
anim = ca.generateTwoDimensionalSequence()

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
animate.save('anim_conway.mp4',extra_args=['-vcodec','libx264'])
fig.show() 

#chip = ca.chipSequence(sequence, 5, 5, 2, 3)



