from automata.automata import Automata, Cell, Conway
import time
from matplotlib import pyplot as plt
from matplotlib import animation
import numpy as np

# reflectionless rotator
ca = Conway("B3/S23/2", 40, 1, .37, 100)
ca.initializeTwoDimensionalEmptyCells()
ca.placeObject("xp30_w33z8kqrqk8zzzx33", 5, 5, True)


# ca = Conway("B3/S23/2", 40, 1, .37, 100)
#
# ca.initializeTwoDimensionalEmptyCells()
#
# ca.placeObject("xp30_w33z8kqrqk8zzzx33", 5, 5, True)
# anim = ca.generateTwoDimensionalSequence()
#
#
# temp_im = np.zeros([len(anim[0]),len(anim[0])])
#
# def init():
#     global fig, ax, im
#     fig = plt.figure()
#     ax = plt.axes()
#     im = ax.imshow(temp_im,interpolation='nearest',cmap=plt.get_cmap('viridis'), animated=True,vmin=0,vmax=11.0)
#     im.set_data(temp_im)
#     return
#
# def animate(i):
#     temp_im = anim[i]
#     im.set_data(temp_im)
#     return
#
# init()
# animate = animation.FuncAnimation(fig, animate, interval=50, frames=len(anim))
# animate.save('refl_rotator.mp4',extra_args=['-vcodec','libx264'])
# fig.show()

#chip = ca.chipSequence(sequence, 5, 5, 2, 3)
