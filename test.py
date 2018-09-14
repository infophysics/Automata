from automata.automata import Automata, Cell
import numpy as np
import matplotlib.pyplot as plt

initialState = [[0 for i in range(301)]]
initialState[0][150] = 1

test = Automata(1, 301, 0, 22, .4, 300)
test.setCells(initialState)
test.displayOneDimensionalCells()
sequence = test.generateOneDimensionalSequence()
test.saveSequenceToFile(sequence, "test2.csv")
plt.figure(figsize = (10,10))
plt.imshow(sequence, interpolation='nearest')
plt.show()

