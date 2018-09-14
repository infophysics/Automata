from automata.automata import Cell, Automata
import numpy as np
import matplotlib.pyplot as plt
import time

automata = Automata(2, 50, 1, 45, .5, 100)
automata.initializeTwoDimensionalCells()
for i in range(10):
    time.sleep(.25)
    automata.displayTwoDimensionalCells()
    automata.updateTwoDimensionalvonNeumannCells()
