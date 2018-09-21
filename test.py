from automata.automata import Automata, Cell
from cubicalRipser.cubicalRipser import CubicalRipser2D
import numpy as np
import matplotlib.pyplot as plt
from diphaFormat import convert_csv_to_dipha

initialState = [[0 for i in range(301)]]
initialState[0][150] = 1

test = Automata(1, 301, 0, 22, .4, 300)
test.initializeOneDimensionalEmptyCells()
test.setCells(initialState)
test.displayOneDimensionalCells()
sequence = test.generateOneDimensionalSequence()
test.saveSequenceToFile(sequence, "test2.csv")

#   save as binary file for DIPHA
convert_csv_to_dipha("test2.csv","test2.complex")

#   run cubical ripser
ripser = CubicalRipser2D()
ripser.ComputeBarcode("test2.complex", "output.csv", "DIPHA", "COMPUTEPAIRS", 99999, True)

plt.figure(figsize = (10,10))
plt.imshow(sequence, interpolation='nearest')
plt.show()

