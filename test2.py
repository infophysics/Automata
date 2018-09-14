from automata.automata import Cell, Automata
import numpy as np
import matplotlib.pyplot as plt
import time

automata = Automata(2, 50, 1, 20, .5, 100)
automata.initializeTwoDimensionalCells()
automata.findTwoDimensionalvonNeumannUpdateRule2()
for i in range(10):
    time.sleep(.1)
    automata.displayTwoDimensionalCells()
    automata.updateTwoDimensionalvonNeumannCells2()
