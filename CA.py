from automata.automata import Automata, Cell, Conway
import time
from matplotlib import pyplot as plt
from matplotlib import animation
import numpy as np
import io
import base64
from IPython.display import HTML

def save_CA(anim, output_fig, show_fig=True):

    temp_im = np.zeros([len(anim[0]),len(anim[0])])

    def init():
        global fig, ax, im
        fig = plt.figure()
        ax = plt.axes()
        im = ax.imshow(temp_im,interpolation='nearest',cmap=plt.get_cmap('viridis'),
                       animated=True,vmin=0,vmax=2.0)
        im.set_data(temp_im)
        return

    def animate(i):
        temp_im = anim[i]
        im.set_data(temp_im)
        return
    
    init()
    animate = animation.FuncAnimation(fig, animate,frames=len(anim))
    animate.save(output_fig,extra_args=['-vcodec','libx264'])
    if (show_fig==True):
        plt.show()

def display_CA(movie_file):
    video = io.open(movie_file, 'r+b').read()
    encoded = base64.b64encode(video)
    return HTML(data='''
            <video controls>
                <source src="data:video/mp4;base64,{0}" type="video/mp4" />
            </video>'''.format(encoded.decode('ascii')))

def display_state(state):
    fig = plt.figure()
    ax = plt.axes()
    im = ax.imshow(state,interpolation='nearest',cmap=plt.get_cmap('viridis'),
                   animated=True,vmin=0,vmax=2.0)
    plt.show()
