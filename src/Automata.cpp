/*
 * Automata.cpp
 *
 *  Created on: Sep 5, 2018
 *      Author: ncarrara
 */

#include "Automata.h"
#include <stdio.h>
#include <unistd.h>

// direction vectors
const int dx[] = {+1, 0, -1, 0};
const int dy[] = {0, +1, 0, -1};

void dfs(std::vector<int> array, std::vector<int> &label, int x, int y, int width, int height, int current_label) {
  if (x < 0 || x == height) return; // out of bounds
  if (y < 0 || y == width) return; // out of bounds
  if (label[x * width + y] || !array[x * width + y]) return; // already labeled or not marked with 1 in m
  // mark the current cell
  label[x * width + y] = current_label;
  // recursively mark the neighbors
  for (int direction = 0; direction < 4; ++direction)
    dfs(array, label, x + dx[direction], y + dy[direction], width, height, current_label);
}

std::vector<int> ConnectedComponents(std::vector<int> array, int width, int height) {
	// 0 unlabeled
	std::vector<int> label(width * height, 0);

	int component_counter = 0;

	for (int i = 0; i < height; ++i)
    for (int j = 0; j < width; ++j)
      if (!label[i * width + j] && array[i * width + j]) {
				dfs(array, label, i, j, width, height, ++component_counter);
			}

	std::cout << component_counter << '\n';
	return label;
}

int* ConnectedComponents(int* array, int width, int height) {
	int* x;
	return x;
}


//	Default constructor
Automata::Automata() : m_Type(0), m_Size(0), m_Boundary(-1), m_Rule(-1), m_Density(0), m_Time(0) { srand(time(NULL));}
Automata::~Automata() {}
//	Various constructors
Automata::Automata(int dim, int size, int numStates) : m_Dim(dim), m_Size(size), m_NumStates(numStates), m_Boundary(-1), m_Rule(-1), m_Type(0), m_Density(0), m_Time(0)  {srand(time(NULL));}
Automata::Automata(int dim, int size, int numStates, int boundary) : m_Dim(dim), m_Size(size), m_NumStates(numStates), m_Boundary(boundary), m_Rule(-1), m_Type(0), m_Density(0), m_Time(0) { srand(time(NULL));}
Automata::Automata(int dim, int size, int numStates, int boundary, int rule) : m_Dim(dim), m_Size(size), m_NumStates(numStates), m_Boundary(boundary), m_Rule(rule), m_Type(0), m_Density(0), m_Time(0) { srand(time(NULL));}
Automata::Automata(int dim, int size, int numStates, int boundary, int rule, int type) : m_Dim(dim), m_Size(size), m_NumStates(numStates), m_Boundary(boundary), m_Rule(rule), m_Type(type), m_Density(0), m_Time(0) { srand(time(NULL));}
Automata::Automata(int dim, int size, int numStates, int boundary, int rule, int type, float density) : m_Dim(dim), m_Size(size), m_NumStates(numStates), m_Boundary(boundary), m_Rule(rule), m_Type(type), m_Density(density), m_Time(0) { srand(time(NULL));}
Automata::Automata(int dim, int size, int numStates, int boundary, int rule, int type, float density, int times) : m_Dim(dim), m_Size(size), m_NumStates(numStates), m_Boundary(boundary), m_Rule(rule), m_Type(type), m_Density(density), m_Time(times){ srand(time(NULL));}




//	states
int Automata::findOneDimensionalState(int cell){
	//	determine type
	if (m_Type == 0){
		if (m_NumStates == 2){
			return findOneDimensionalState_2State(cell);
		}
	}
	else{
		if (m_NumStates == 2){
			return findOneDimensionalState_2State2(cell);
		}
		else if (m_NumStates == 3){
			return findOneDimensionalState_3State2(cell);
		}
	}
}

//	state determination (class 1)
int Automata::findOneDimensionalState_2State(int cell){
	//	check for boundary cells
	if (cell == 0){
		//	check for boundary conditions
		if (m_Boundary == 0){	//	circle topology
			if (m_Cells[0][cell].m_State == 1){
				if (m_Cells[0][m_Size-1].m_State == 1){
					if (m_Cells[0][cell+1].m_State == 1){
						return 0;
					}
					else{
						return 1;
					}
				}
				else{
					if (m_Cells[0][cell+1].m_State == 1){
						return 4;
					}
					else{
						return 5;
					}
				}
			}
			else{
				if (m_Cells[0][m_Size-1].m_State == 1){
					if (m_Cells[0][cell+1].m_State == 1){
						return 2;
					}
					else{
						return 3;
					}
				}
				else{
					if (m_Cells[0][cell+1].m_State == 1){
						return 6;
					}
					else{
						return 7;
					}
				}
			}
		}
	}
	else if (cell == m_Size - 1){
		//	check for boundary conditions
		if (m_Boundary == 0){	//	circle topology
			if (m_Cells[0][cell].m_State == 1){
				if (m_Cells[0][cell-1].m_State == 1){
					if (m_Cells[0][0].m_State == 1){
						return 0;
					}
					else{
						return 1;
					}
				}
				else{
					if (m_Cells[0][0].m_State == 1){
						return 4;
					}
					else{
						return 5;
					}
				}
			}
			else{
				if (m_Cells[0][cell-1].m_State == 1){
					if (m_Cells[0][0].m_State == 1){
						return 2;
					}
					else{
						return 3;
					}
				}
				else{
					if (m_Cells[0][0].m_State == 1){
						return 6;
					}
					else{
						return 7;
					}
				}
			}
		}
	}
	else{
		//	check for boundary conditions
		if (m_Boundary == 0){	//	circle topology
			if (m_Cells[0][cell].m_State == 1){
				if (m_Cells[0][cell-1].m_State == 1){
					if (m_Cells[0][cell+1].m_State == 1){
						return 0;
					}
					else{
						return 1;
					}
				}
				else{
					if (m_Cells[0][cell+1].m_State == 1){
						return 4;
					}
					else{
						return 5;
					}
				}
			}
			else{
				if (m_Cells[0][cell-1].m_State == 1){
					if (m_Cells[0][cell+1].m_State == 1){
						return 2;
					}
					else{
						return 3;
					}
				}
				else{
					if (m_Cells[0][cell+1].m_State == 1){
						return 6;
					}
					else{
						return 7;
					}
				}
			}
		}
	}
}

int Automata::findOneDimensionalState_2State2(int cell){
	//	check for boundary cells
	if (cell == 0){
		//	check for boundary conditions
		if (m_Boundary == 0){	//	circle topology
			return (m_Cells[0][0].m_State + m_Cells[0][m_Size-1].m_State + m_Cells[0][1].m_State);
		}
		else{
			return (m_Cells[0][0].m_State + m_Cells[0][1].m_State);
		}
	}
	else if (cell == m_Size - 1){
		//	check for boundary conditions
		if (m_Boundary == 0){	//	circle topology
			return (m_Cells[0][0].m_State + m_Cells[0][m_Size-1].m_State + m_Cells[0][m_Size - 2].m_State);
		}
		else{
			return (m_Cells[0][m_Size-1].m_State + m_Cells[0][m_Size - 2].m_State);
		}
	}
	else{
		return (m_Cells[0][cell].m_State + m_Cells[0][cell-1].m_State + m_Cells[0][cell+1].m_State);
	}
}

int Automata::findOneDimensionalState_3State2(int cell){
	//	check for boundary cells
	if (cell == 0){
		//	check for boundary conditions
		if (m_Boundary == 0){	//	circle topology
			return (m_Cells[0][0].m_State + m_Cells[0][m_Size-1].m_State + m_Cells[0][1].m_State);
		}
		else{
			return (m_Cells[0][0].m_State + m_Cells[0][1].m_State);
		}
	}
	else if (cell == m_Size - 1){
		//	check for boundary conditions
		if (m_Boundary == 0){	//	circle topology
			return (m_Cells[0][0].m_State + m_Cells[0][m_Size-1].m_State + m_Cells[0][m_Size - 2].m_State);
		}
		else{
			return (m_Cells[0][m_Size-1].m_State + m_Cells[0][m_Size - 2].m_State);
		}
	}
	else{
		return (m_Cells[0][cell].m_State + m_Cells[0][cell-1].m_State + m_Cells[0][cell+1].m_State);
	}
}

//	CAUTION: this does not apply to hard boundary conditions or a sphere or a projective plane
int Automata::findTwoDimensionalvonNeumannState_2State(int cellX, int cellY){
	//	create temporary vector of five elements
	int tempState[5];
	tempState[0] = m_Cells[cellX][cellY].m_State;
	//	check boundary conditions
	if (cellX == 0){	// top of grid
		if (cellY == 0){	// top left
			if (m_Boundary == 1){
				tempState[1] = m_Cells[m_Size-1][0].m_State;
				tempState[2] = m_Cells[1][0].m_State;
				tempState[3] = m_Cells[0][m_Size-1].m_State;
				tempState[4] = m_Cells[0][1].m_State;
			}
			if (m_Boundary == 3){	//	Klein bottle
				tempState[1] = m_Cells[m_Size-1][0].m_State;
				tempState[2] = m_Cells[1][0].m_State;
				tempState[3] = m_Cells[m_Size-1][m_Size-1].m_State;
				tempState[4] = m_Cells[0][1].m_State;
			}
		}
		else if (cellY == m_Size-1){	//	top right
			if (m_Boundary == 1){
				tempState[1] = m_Cells[m_Size-1][m_Size-1].m_State;
				tempState[2] = m_Cells[1][m_Size-1].m_State;
				tempState[3] = m_Cells[0][m_Size-2].m_State;
				tempState[4] = m_Cells[0][0].m_State;
			}
			if (m_Boundary == 3){	//	Klein bottle
				tempState[1] = m_Cells[m_Size-1][m_Size-1].m_State;
				tempState[2] = m_Cells[1][m_Size-1].m_State;
				tempState[3] = m_Cells[0][m_Size-2].m_State;
				tempState[4] = m_Cells[m_Size-1][0].m_State;
			}
		}
		else{	//	middle
			tempState[1] = m_Cells[m_Size-1][cellY].m_State;
			tempState[2] = m_Cells[cellX+1][cellY].m_State;
			tempState[3] = m_Cells[cellX][cellY-1].m_State;
			tempState[4] = m_Cells[cellX][cellY+1].m_State;
		}
	}
	else if (cellX == m_Size - 1){	//	bottom of grid
		if (cellY == 0){	// bottom left
			if (m_Boundary == 1){
				tempState[1] = m_Cells[m_Size-2][0].m_State;
				tempState[2] = m_Cells[0][0].m_State;
				tempState[3] = m_Cells[m_Size-1][m_Size-1].m_State;
				tempState[4] = m_Cells[m_Size-1][1].m_State;
			}
			if (m_Boundary == 3){	//	Klein bottle
				tempState[1] = m_Cells[m_Size-2][0].m_State;
				tempState[2] = m_Cells[0][0].m_State;
				tempState[3] = m_Cells[0][m_Size-1].m_State;
				tempState[4] = m_Cells[m_Size-1][1].m_State;
			}
		}
		else if (cellY == m_Size-1){	//	bottom right
			if (m_Boundary == 1){
				tempState[1] = m_Cells[m_Size-2][m_Size-1].m_State;
				tempState[2] = m_Cells[0][m_Size-1].m_State;
				tempState[3] = m_Cells[m_Size-2][m_Size-2].m_State;
				tempState[4] = m_Cells[m_Size-1][0].m_State;
			}
			if (m_Boundary == 3){	//	Klein bottle
				tempState[1] = m_Cells[m_Size-2][m_Size-1].m_State;
				tempState[2] = m_Cells[0][m_Size-1].m_State;
				tempState[3] = m_Cells[m_Size-2][m_Size-2].m_State;
				tempState[4] = m_Cells[0][0].m_State;
			}
		}
		else{	//	middle
			tempState[1] = m_Cells[cellX-1][cellY].m_State;
			tempState[2] = m_Cells[0][cellY].m_State;
			tempState[3] = m_Cells[cellX][cellY-1].m_State;
			tempState[4] = m_Cells[cellX][cellY+1].m_State;
		}
	}
	else{
		if (cellY == 0){	// middle left
			if (m_Boundary == 1){
				tempState[1] = m_Cells[cellX-1][0].m_State;
				tempState[2] = m_Cells[cellX+1][0].m_State;
				tempState[3] = m_Cells[cellX][m_Size-1].m_State;
				tempState[4] = m_Cells[cellX][1].m_State;
			}
			if (m_Boundary == 3){	//	Klein bottle
				tempState[1] = m_Cells[cellX-1][0].m_State;
				tempState[2] = m_Cells[cellX+1][0].m_State;
				tempState[3] = m_Cells[m_Size-cellX][m_Size-1].m_State;
				tempState[4] = m_Cells[cellX][1].m_State;
			}
		}
		else if (cellY == m_Size-1){	//	middle right
			if (m_Boundary == 1){
				tempState[1] = m_Cells[cellX-1][m_Size-1].m_State;
				tempState[2] = m_Cells[cellX+1][m_Size-1].m_State;
				tempState[3] = m_Cells[cellX][cellY-1].m_State;
				tempState[4] = m_Cells[cellX][0].m_State;
			}
			if (m_Boundary == 3){	//	Klein bottle
				tempState[1] = m_Cells[cellX-1][m_Size-1].m_State;
				tempState[2] = m_Cells[cellX+1][m_Size-1].m_State;
				tempState[3] = m_Cells[cellX][cellY-1].m_State;
				tempState[4] = m_Cells[m_Size-1-cellX][0].m_State;
			}
		}
		else{	//	middle
			tempState[1] = m_Cells[cellX-1][cellY].m_State;
			tempState[2] = m_Cells[cellX+1][cellY].m_State;
			tempState[3] = m_Cells[cellX][cellY-1].m_State;
			tempState[4] = m_Cells[cellX][cellY+1].m_State;
		}
	}
	return (tempState[0] + tempState[1]*2 + tempState[2]*4 + tempState[3]*8 + tempState[4]*16);
}

int Automata::findTwoDimensionalvonNeumannState_2State2(int cellX, int cellY){
	//	create temporary vector of five elements
	int tempState[5];
	tempState[0] = m_Cells[cellX][cellY].m_State;
	//	check boundary conditions
	if (cellX == 0){	// top of grid
		if (cellY == 0){	// top left
			if (m_Boundary == 1){
				tempState[1] = m_Cells[m_Size-1][0].m_State;
				tempState[2] = m_Cells[1][0].m_State;
				tempState[3] = m_Cells[0][m_Size-1].m_State;
				tempState[4] = m_Cells[0][1].m_State;
			}
			if (m_Boundary == 3){	//	Klein bottle
				tempState[1] = m_Cells[m_Size-1][0].m_State;
				tempState[2] = m_Cells[1][0].m_State;
				tempState[3] = m_Cells[m_Size-1][m_Size-1].m_State;
				tempState[4] = m_Cells[0][1].m_State;
			}
		}
		else if (cellY == m_Size-1){	//	top right
			if (m_Boundary == 1){
				tempState[1] = m_Cells[m_Size-1][m_Size-1].m_State;
				tempState[2] = m_Cells[1][m_Size-1].m_State;
				tempState[3] = m_Cells[0][m_Size-2].m_State;
				tempState[4] = m_Cells[0][0].m_State;
			}
			if (m_Boundary == 3){	//	Klein bottle
				tempState[1] = m_Cells[m_Size-1][m_Size-1].m_State;
				tempState[2] = m_Cells[1][m_Size-1].m_State;
				tempState[3] = m_Cells[0][m_Size-2].m_State;
				tempState[4] = m_Cells[m_Size-1][0].m_State;
			}
		}
		else{	//	middle
			tempState[1] = m_Cells[m_Size-1][cellY].m_State;
			tempState[2] = m_Cells[cellX+1][cellY].m_State;
			tempState[3] = m_Cells[cellX][cellY-1].m_State;
			tempState[4] = m_Cells[cellX][cellY+1].m_State;
		}
	}
	else if (cellX == m_Size - 1){	//	bottom of grid
		if (cellY == 0){	// bottom left
			if (m_Boundary == 1){
				tempState[1] = m_Cells[m_Size-2][0].m_State;
				tempState[2] = m_Cells[0][0].m_State;
				tempState[3] = m_Cells[m_Size-1][m_Size-1].m_State;
				tempState[4] = m_Cells[m_Size-1][1].m_State;
			}
			if (m_Boundary == 3){	//	Klein bottle
				tempState[1] = m_Cells[m_Size-2][0].m_State;
				tempState[2] = m_Cells[0][0].m_State;
				tempState[3] = m_Cells[0][m_Size-1].m_State;
				tempState[4] = m_Cells[m_Size-1][1].m_State;
			}
		}
		else if (cellY == m_Size-1){	//	bottom right
			if (m_Boundary == 1){
				tempState[1] = m_Cells[m_Size-2][m_Size-1].m_State;
				tempState[2] = m_Cells[0][m_Size-1].m_State;
				tempState[3] = m_Cells[m_Size-2][m_Size-2].m_State;
				tempState[4] = m_Cells[m_Size-1][0].m_State;
			}
			if (m_Boundary == 3){	//	Klein bottle
				tempState[1] = m_Cells[m_Size-2][m_Size-1].m_State;
				tempState[2] = m_Cells[0][m_Size-1].m_State;
				tempState[3] = m_Cells[m_Size-2][m_Size-2].m_State;
				tempState[4] = m_Cells[0][0].m_State;
			}
		}
		else{	//	middle
			tempState[1] = m_Cells[cellX-1][cellY].m_State;
			tempState[2] = m_Cells[0][cellY].m_State;
			tempState[3] = m_Cells[cellX][cellY-1].m_State;
			tempState[4] = m_Cells[cellX][cellY+1].m_State;
		}
	}
	else{
		if (cellY == 0){	// middle left
			if (m_Boundary == 1){
				tempState[1] = m_Cells[cellX-1][0].m_State;
				tempState[2] = m_Cells[cellX+1][0].m_State;
				tempState[3] = m_Cells[cellX][m_Size-1].m_State;
				tempState[4] = m_Cells[cellX][1].m_State;
			}
			if (m_Boundary == 3){	//	Klein bottle
				tempState[1] = m_Cells[cellX-1][0].m_State;
				tempState[2] = m_Cells[cellX+1][0].m_State;
				tempState[3] = m_Cells[m_Size-cellX][m_Size-1].m_State;
				tempState[4] = m_Cells[cellX][1].m_State;
			}
		}
		else if (cellY == m_Size-1){	//	middle right
			if (m_Boundary == 1){
				tempState[1] = m_Cells[cellX-1][m_Size-1].m_State;
				tempState[2] = m_Cells[cellX+1][m_Size-1].m_State;
				tempState[3] = m_Cells[cellX][cellY-1].m_State;
				tempState[4] = m_Cells[cellX][0].m_State;
			}
			if (m_Boundary == 3){	//	Klein bottle
				tempState[1] = m_Cells[cellX-1][m_Size-1].m_State;
				tempState[2] = m_Cells[cellX+1][m_Size-1].m_State;
				tempState[3] = m_Cells[cellX][cellY-1].m_State;
				tempState[4] = m_Cells[m_Size-1-cellX][0].m_State;
			}
		}
		else{	//	middle
			tempState[1] = m_Cells[cellX-1][cellY].m_State;
			tempState[2] = m_Cells[cellX+1][cellY].m_State;
			tempState[3] = m_Cells[cellX][cellY-1].m_State;
			tempState[4] = m_Cells[cellX][cellY+1].m_State;
		}
	}
	return (tempState[0]*5 + tempState[1] + tempState[2] + tempState[3] + tempState[4]);
}


int Automata::findTwoDimensionalMooreState_2State2(int cellX, int cellY){
	int currentCell = m_Cells[cellX][cellY].m_State * 9;
	//	check for boundary cells
	if (cellX == 0){	//	top of grid
		if (cellY == 0){	//	top left
			//	check boundary conditions
			if (m_Boundary == 0){	//	sphere topology
				return currentCell + m_Cells[0][1].m_State + m_Cells[1][0].m_State + m_Cells[1][1].m_State;
			}
			else if (m_Boundary == 1){	//	torus topology
				return currentCell + m_Cells[0][1].m_State + m_Cells[1][0].m_State + m_Cells[1][1].m_State + m_Cells[0][m_Size-1].m_State + m_Cells[1][m_Size-1].m_State + m_Cells[m_Size-1][0].m_State + m_Cells[m_Size-1][1].m_State + m_Cells[m_Size-1][m_Size-1].m_State;
			}
			else if (m_Boundary == 2){	//	cylinder topology
				return currentCell + m_Cells[0][1].m_State + m_Cells[1][0].m_State + m_Cells[1][1].m_State + m_Cells[0][m_Size-1].m_State + m_Cells[1][m_Size-1].m_State;
			}
			else if (m_Boundary == 3){	//	Klein bottle topology
				return currentCell + m_Cells[0][1].m_State + m_Cells[1][0].m_State + m_Cells[1][1].m_State + m_Cells[0][m_Size-1].m_State + m_Cells[1][m_Size-1].m_State + m_Cells[m_Size-1][0].m_State + m_Cells[m_Size-1][m_Size-2].m_State + m_Cells[m_Size-1][m_Size-1].m_State;
			}
			else if (m_Boundary == 4){	//	Mobius strip topology
				return currentCell + m_Cells[0][1].m_State + m_Cells[1][0].m_State + m_Cells[1][1].m_State + m_Cells[m_Size-2][m_Size-1].m_State + m_Cells[m_Size-1][m_Size-1].m_State;
			}
			else{	//	square topology
				return currentCell + m_Cells[0][1].m_State + m_Cells[1][0].m_State + m_Cells[1][1].m_State;
			}
		}
		else if (cellY == m_Size - 1){
			if (m_Boundary == 0){	//	sphere topology
				return currentCell + m_Cells[0][m_Size-2].m_State + m_Cells[1][m_Size-2].m_State + m_Cells[1][m_Size-1].m_State;
			}
			else if (m_Boundary == 1){	//	torus topology
				return currentCell + m_Cells[0][m_Size-2].m_State + m_Cells[1][m_Size-2].m_State + m_Cells[1][m_Size-1].m_State + m_Cells[0][0].m_State + m_Cells[1][0].m_State + m_Cells[m_Size-1][0].m_State + m_Cells[m_Size-1][m_Size-2].m_State + m_Cells[m_Size-1][m_Size-1].m_State;
			}
			else if (m_Boundary == 2){	//	cylinder topology
				return currentCell + m_Cells[0][m_Size-2].m_State + m_Cells[1][m_Size-2].m_State + m_Cells[1][m_Size-1].m_State + m_Cells[0][0].m_State + m_Cells[1][0].m_State;
			}
			else if (m_Boundary == 3){	//	Klein bottle topology
				return currentCell + m_Cells[0][m_Size-2].m_State + m_Cells[1][m_Size-2].m_State + m_Cells[1][m_Size-1].m_State + m_Cells[0][0].m_State + m_Cells[1][0].m_State + m_Cells[m_Size-1][0].m_State + m_Cells[m_Size-1][1].m_State + m_Cells[m_Size-1][m_Size-1].m_State;
			}
			else if (m_Boundary == 4){	//	Mobius strip topology
				return currentCell + m_Cells[0][m_Size-2].m_State + m_Cells[1][m_Size-2].m_State + m_Cells[1][m_Size-1].m_State + m_Cells[m_Size-2][0].m_State + m_Cells[m_Size-1][0].m_State;
			}
			else{	//	square topology
				return currentCell + m_Cells[0][m_Size-2].m_State + m_Cells[1][m_Size-2].m_State + m_Cells[1][m_Size-1].m_State;
			}
		}
		else{
			if (m_Boundary == 0){	//	sphere topology
				return currentCell + m_Cells[0][cellY-1].m_State + m_Cells[0][cellY+1].m_State + m_Cells[1][cellY-1].m_State + m_Cells[1][cellY].m_State + m_Cells[1][cellY+1].m_State;
			}
			else if (m_Boundary == 1){	//	torus topology
				return currentCell + m_Cells[0][cellY-1].m_State + m_Cells[0][cellY+1].m_State + m_Cells[1][cellY-1].m_State + m_Cells[1][cellY].m_State + m_Cells[1][cellY+1].m_State + m_Cells[m_Size-1][cellY-1].m_State + m_Cells[m_Size-1][cellY].m_State + m_Cells[m_Size-1][cellY+1].m_State;
			}
			else if (m_Boundary == 2){	//	cylinder topology
				return currentCell + m_Cells[0][cellY-1].m_State + m_Cells[0][cellY+1].m_State + m_Cells[1][cellY-1].m_State + m_Cells[1][cellY].m_State + m_Cells[1][cellY+1].m_State;
			}
			else if (m_Boundary == 3){	//	Klein bottle topology
				return currentCell + m_Cells[0][cellY-1].m_State + m_Cells[0][cellY+1].m_State + m_Cells[1][cellY-1].m_State + m_Cells[1][cellY].m_State + m_Cells[1][cellY+1].m_State + m_Cells[m_Size-1][m_Size-cellY-1].m_State + m_Cells[m_Size-1][m_Size-cellY].m_State + m_Cells[m_Size-1][m_Size-cellY+1].m_State;
			}
			else if (m_Boundary == 4){	//	Mobius strip topology
				return currentCell + m_Cells[0][cellY-1].m_State + m_Cells[0][cellY+1].m_State + m_Cells[1][cellY-1].m_State + m_Cells[1][cellY].m_State + m_Cells[1][cellY+1].m_State;
			}
			else{	//	square topology
				return currentCell + m_Cells[0][cellY-1].m_State + m_Cells[0][cellY+1].m_State + m_Cells[1][cellY-1].m_State + m_Cells[1][cellY].m_State + m_Cells[1][cellY+1].m_State;
			}
		}
	}
	else if (cellX == m_Size-1){
		if (cellY == 0){	//	top left
			//	check boundary conditions
			if (m_Boundary == 0){	//	sphere topology
				return currentCell + m_Cells[m_Size-1][1].m_State + m_Cells[m_Size-2][0].m_State + m_Cells[m_Size-2][1].m_State;
			}
			else if (m_Boundary == 1){	//	torus topology
				return currentCell + m_Cells[m_Size-1][1].m_State + m_Cells[m_Size-2][0].m_State + m_Cells[m_Size-2][1].m_State + m_Cells[m_Size-1][m_Size-1].m_State + m_Cells[m_Size-2][m_Size-1].m_State + m_Cells[0][0].m_State + m_Cells[0][1].m_State + m_Cells[0][m_Size-1].m_State;
			}
			else if (m_Boundary == 2){	//	cylinder topology
				return currentCell + m_Cells[m_Size-1][1].m_State + m_Cells[m_Size-2][0].m_State + m_Cells[m_Size-2][1].m_State + m_Cells[m_Size-1][m_Size-1].m_State + m_Cells[m_Size-2][m_Size-1].m_State;
			}
			else if (m_Boundary == 3){	//	Klein bottle topology
				return currentCell + m_Cells[m_Size-1][1].m_State + m_Cells[m_Size-2][0].m_State + m_Cells[m_Size-2][1].m_State + m_Cells[m_Size-1][m_Size-1].m_State + m_Cells[m_Size-2][m_Size-1].m_State + m_Cells[0][0].m_State + m_Cells[0][m_Size-2].m_State + m_Cells[0][m_Size-1].m_State;
			}
			else if (m_Boundary == 4){	//	Mobius strip topology
				return currentCell + m_Cells[m_Size-1][1].m_State + m_Cells[m_Size-2][0].m_State + m_Cells[m_Size-2][1].m_State + m_Cells[1][m_Size-1].m_State + m_Cells[0][m_Size-1].m_State;
			}
			else{	//	square topology
				return currentCell + m_Cells[m_Size-1][1].m_State + m_Cells[m_Size-2][0].m_State + m_Cells[m_Size-2][1].m_State;
			}
		}
		else if (cellY == m_Size - 1){
			if (m_Boundary == 0){	//	sphere topology
				return currentCell + m_Cells[m_Size-1][m_Size-2].m_State + m_Cells[m_Size-2][m_Size-2].m_State + m_Cells[m_Size-2][m_Size-1].m_State;
			}
			else if (m_Boundary == 1){	//	torus topology
				return currentCell + m_Cells[m_Size-1][m_Size-2].m_State + m_Cells[m_Size-2][m_Size-2].m_State + m_Cells[m_Size-2][m_Size-1].m_State + m_Cells[m_Size-1][0].m_State + m_Cells[m_Size-2][0].m_State + m_Cells[0][0].m_State + m_Cells[0][m_Size-2].m_State + m_Cells[0][m_Size-1].m_State;
			}
			else if (m_Boundary == 2){	//	cylinder topology
				return currentCell + m_Cells[m_Size-1][m_Size-2].m_State + m_Cells[m_Size-2][m_Size-2].m_State + m_Cells[m_Size-2][m_Size-1].m_State + m_Cells[m_Size-1][0].m_State + m_Cells[m_Size-2][0].m_State;
			}
			else if (m_Boundary == 3){	//	Klein bottle topology
				return currentCell + m_Cells[m_Size-1][m_Size-2].m_State + m_Cells[m_Size-2][m_Size-2].m_State + m_Cells[m_Size-2][m_Size-1].m_State + m_Cells[m_Size-1][0].m_State + m_Cells[m_Size-2][0].m_State + m_Cells[0][0].m_State + m_Cells[0][1].m_State + m_Cells[0][m_Size-1].m_State;
			}
			else if (m_Boundary == 4){	//	Mobius strip topology
				return currentCell + m_Cells[m_Size-1][m_Size-2].m_State + m_Cells[m_Size-2][m_Size-2].m_State + m_Cells[m_Size-2][m_Size-1].m_State + m_Cells[1][0].m_State + m_Cells[0][0].m_State;
			}
			else{	//	square topology
				return currentCell + m_Cells[m_Size-1][m_Size-2].m_State + m_Cells[m_Size-2][m_Size-2].m_State + m_Cells[m_Size-2][m_Size-1].m_State;
			}
		}
		else{
			if (m_Boundary == 0){	//	sphere topology
				return currentCell + m_Cells[m_Size-1][cellY-1].m_State + m_Cells[m_Size-1][cellY+1].m_State + m_Cells[m_Size-2][cellY-1].m_State + m_Cells[m_Size-2][cellY].m_State + m_Cells[m_Size-2][cellY+1].m_State;
			}
			else if (m_Boundary == 1){	//	torus topology
				return currentCell + m_Cells[m_Size-1][cellY-1].m_State + m_Cells[m_Size-1][cellY+1].m_State + m_Cells[m_Size-2][cellY-1].m_State + m_Cells[m_Size-2][cellY].m_State + m_Cells[m_Size-2][cellY+1].m_State + m_Cells[0][cellY-1].m_State + m_Cells[0][cellY].m_State + m_Cells[0][cellY+1].m_State;
			}
			else if (m_Boundary == 2){	//	cylinder topology
				return currentCell + m_Cells[m_Size-1][cellY-1].m_State + m_Cells[m_Size-1][cellY+1].m_State + m_Cells[m_Size-2][cellY-1].m_State + m_Cells[m_Size-2][cellY].m_State + m_Cells[m_Size-2][cellY+1].m_State;
			}
			else if (m_Boundary == 3){	//	Klein bottle topology
				return currentCell + m_Cells[m_Size-1][cellY-1].m_State + m_Cells[m_Size-1][cellY+1].m_State + m_Cells[m_Size-2][cellY-1].m_State + m_Cells[m_Size-2][cellY].m_State + m_Cells[m_Size-2][cellY+1].m_State + m_Cells[0][m_Size-cellY-1].m_State + m_Cells[0][m_Size-cellY].m_State + m_Cells[0][m_Size-cellY+1].m_State;
			}
			else if (m_Boundary == 4){	//	Mobius strip topology
				return currentCell + m_Cells[m_Size-1][cellY-1].m_State + m_Cells[m_Size-1][cellY+1].m_State + m_Cells[m_Size-2][cellY-1].m_State + m_Cells[m_Size-2][cellY].m_State + m_Cells[m_Size-2][cellY+1].m_State;
			}
			else{	//	square topology
				return currentCell + m_Cells[m_Size-1][cellY-1].m_State + m_Cells[m_Size-1][cellY+1].m_State + m_Cells[m_Size-2][cellY-1].m_State + m_Cells[m_Size-2][cellY].m_State + m_Cells[m_Size-2][cellY+1].m_State;
			}
		}
	}
	else{	//sides
		if (cellY == 0){	//	top left
			//	check boundary conditions
			if (m_Boundary == 0){	//	sphere topology
				return currentCell + m_Cells[cellX][1].m_State + m_Cells[cellX-1][0].m_State + m_Cells[cellX-1][1].m_State + m_Cells[cellX+1][0].m_State + m_Cells[cellX+1][1].m_State;
			}
			else if (m_Boundary == 1){	//	torus topology
				return currentCell + m_Cells[cellX][1].m_State + m_Cells[cellX-1][0].m_State + m_Cells[cellX-1][1].m_State + m_Cells[cellX+1][0].m_State + m_Cells[cellX+1][1].m_State + m_Cells[cellX-1][m_Size-1].m_State + m_Cells[cellX+1][m_Size-1].m_State + m_Cells[cellX][m_Size-1].m_State;
			}
			else if (m_Boundary == 2){	//	cylinder topology
				return currentCell + m_Cells[cellX][1].m_State + m_Cells[cellX-1][0].m_State + m_Cells[cellX-1][1].m_State + m_Cells[cellX+1][0].m_State + m_Cells[cellX+1][1].m_State + m_Cells[cellX-1][m_Size-1].m_State + m_Cells[cellX+1][m_Size-1].m_State + m_Cells[cellX][m_Size-1].m_State;
			}
			else if (m_Boundary == 3){	//	Klein bottle topology
				return currentCell + m_Cells[cellX][1].m_State + m_Cells[cellX-1][0].m_State + m_Cells[cellX-1][1].m_State + m_Cells[cellX+1][0].m_State + m_Cells[cellX+1][1].m_State + m_Cells[cellX-1][m_Size-1].m_State + m_Cells[cellX+1][m_Size-1].m_State + m_Cells[cellX][m_Size-1].m_State;
			}
			else if (m_Boundary == 4){	//	Mobius strip topology
				return currentCell + m_Cells[cellX][1].m_State + m_Cells[cellX-1][0].m_State + m_Cells[cellX-1][1].m_State + m_Cells[cellX+1][0].m_State + m_Cells[cellX+1][1].m_State + m_Cells[m_Size-cellX-1][m_Size-1].m_State + m_Cells[m_Size-cellX+1][m_Size-1].m_State + m_Cells[m_Size-cellX][m_Size-1].m_State;
			}
			else{	//	square topology
				return currentCell + m_Cells[cellX][1].m_State + m_Cells[cellX-1][0].m_State + m_Cells[cellX-1][1].m_State + m_Cells[cellX+1][0].m_State + m_Cells[cellX+1][1].m_State;
			}
		}
		else if (cellY == m_Size - 1){
			if (m_Boundary == 0){	//	sphere topology
				return currentCell + m_Cells[cellX][m_Size-2].m_State + m_Cells[cellX-1][m_Size-1].m_State + m_Cells[cellX-1][m_Size-2].m_State + m_Cells[cellX+1][m_Size-1].m_State + m_Cells[cellX+1][m_Size-2].m_State;
			}
			else if (m_Boundary == 1){	//	torus topology
				return currentCell + m_Cells[cellX][m_Size-2].m_State + m_Cells[cellX-1][m_Size-1].m_State + m_Cells[cellX-1][m_Size-2].m_State + m_Cells[cellX+1][m_Size-1].m_State + m_Cells[cellX+1][m_Size-2].m_State + m_Cells[cellX-1][0].m_State + m_Cells[cellX][0].m_State + m_Cells[cellX+1][0].m_State;
			}
			else if (m_Boundary == 2){	//	cylinder topology
				return currentCell + m_Cells[cellX][m_Size-2].m_State + m_Cells[cellX-1][m_Size-1].m_State + m_Cells[cellX-1][m_Size-2].m_State + m_Cells[cellX+1][m_Size-1].m_State + m_Cells[cellX+1][m_Size-2].m_State + m_Cells[cellX-1][0].m_State + m_Cells[cellX][0].m_State + m_Cells[cellX+1][0].m_State;
			}
			else if (m_Boundary == 3){	//	Klein bottle topology
				return currentCell + m_Cells[cellX][m_Size-2].m_State + m_Cells[cellX-1][m_Size-1].m_State + m_Cells[cellX-1][m_Size-2].m_State + m_Cells[cellX+1][m_Size-1].m_State + m_Cells[cellX+1][m_Size-2].m_State + m_Cells[cellX-1][0].m_State + m_Cells[cellX][0].m_State + m_Cells[cellX+1][0].m_State;
			}
			else if (m_Boundary == 4){	//	Mobius strip topology
				return currentCell + m_Cells[cellX][m_Size-2].m_State + m_Cells[cellX-1][m_Size-1].m_State + m_Cells[cellX-1][m_Size-2].m_State + m_Cells[cellX+1][m_Size-1].m_State + m_Cells[cellX+1][m_Size-2].m_State + m_Cells[m_Size-cellX-1][0].m_State + m_Cells[m_Size-cellX][0].m_State + m_Cells[m_Size-cellX+1][0].m_State;
			}
			else{	//	square topology
				return currentCell + m_Cells[cellX][m_Size-2].m_State + m_Cells[cellX-1][m_Size-1].m_State + m_Cells[cellX-1][m_Size-2].m_State + m_Cells[cellX+1][m_Size-1].m_State + m_Cells[cellX+1][m_Size-2].m_State;
			}
		}
		else{
			return currentCell + m_Cells[cellX][cellY+1].m_State + m_Cells[cellX][cellY-1].m_State + m_Cells[cellX+1][cellY-1].m_State + m_Cells[cellX+1][cellY].m_State + m_Cells[cellX+1][cellY+1].m_State + m_Cells[cellX-1][cellY-1].m_State + m_Cells[cellX-1][cellY].m_State + m_Cells[cellX-1][cellY+1].m_State;
		}
	}
}

int Automata::findTwoDimensionalMooreState_NState2(int cellX, int cellY){
	int currentCell = m_Cells[cellX][cellY].m_State * 9;
	int numLive = 0;
	//	check for boundary cells
	if (cellX == 0){	//	top of grid
		if (cellY == 0){	//	top left
			//	check boundary conditions
			if (m_Boundary == 0){
				if (m_Cells[0][1].m_State == 1) numLive +=1;
				if (m_Cells[1][0].m_State == 1) numLive +=1;
				if (m_Cells[1][1].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 1){	//	torus topology
				if (m_Cells[0][1].m_State == 1) numLive +=1;
				if (m_Cells[1][0].m_State == 1) numLive +=1;
				if (m_Cells[1][1].m_State == 1) numLive +=1;
				if (m_Cells[0][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][0].m_State == 1) numLive +=1;;
				if (m_Cells[m_Size-1][1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][m_Size-1].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 2){	//	cylinder topology
				if (m_Cells[0][1].m_State == 1) numLive +=1;
				if (m_Cells[1][0].m_State == 1) numLive +=1;
				if (m_Cells[1][1].m_State == 1) numLive +=1;
				if (m_Cells[0][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[1][m_Size-1].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 3){	//	Klein bottle topology
				if (m_Cells[0][1].m_State == 1) numLive +=1;
				if (m_Cells[1][0].m_State == 1) numLive +=1;
				if (m_Cells[1][1].m_State == 1) numLive +=1;
				if (m_Cells[0][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][0].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][m_Size-1].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 4){	//	Mobius strip topology
				if (m_Cells[0][1].m_State == 1) numLive +=1;
				if (m_Cells[1][0].m_State == 1) numLive +=1;
				if (m_Cells[1][1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][m_Size-1].m_State == 1) numLive +=1;
			}
			else{	//	square topology
				if (m_Cells[0][1].m_State == 1) numLive +=1;
				if (m_Cells[1][0].m_State == 1) numLive +=1;
				if (m_Cells[1][1].m_State == 1) numLive +=1;
			}
		}
		else if (cellY == m_Size - 1){
			if (m_Boundary == 0){	//	sphere topology
				if (m_Cells[0][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[1][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[1][m_Size-1].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 1){	//	torus topology
				if (m_Cells[0][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[1][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[0][0].m_State == 1) numLive +=1;
				if (m_Cells[1][0].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][0].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][m_Size-1].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 2){	//	cylinder topology
				if (m_Cells[0][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[1][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[0][0].m_State == 1) numLive +=1;
				if (m_Cells[1][0].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 3){	//	Klein bottle topology
				if (m_Cells[0][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[1][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[0][0].m_State == 1) numLive +=1;
				if (m_Cells[1][0].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][0].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][m_Size-1].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 4){	//	Mobius strip topology
				if (m_Cells[0][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[1][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][0].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][0].m_State == 1) numLive +=1;
			}
			else{	//	square topology
				if (m_Cells[0][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[1][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[1][m_Size-1].m_State == 1) numLive +=1;
			}
		}
		else{
			if (m_Boundary == 0){	//	sphere topology
				if (m_Cells[0][cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[0][cellY+1].m_State == 1) numLive +=1;
				if (m_Cells[1][cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[1][cellY].m_State == 1) numLive +=1;
				if (m_Cells[1][cellY+1].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 1){	//	torus topology
				if (m_Cells[0][cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[0][cellY+1].m_State == 1) numLive +=1;
				if (m_Cells[1][cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[1][cellY].m_State == 1) numLive +=1;
				if (m_Cells[1][cellY+1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][cellY].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][cellY+1].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 2){	//	cylinder topology
				if (m_Cells[0][cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[0][cellY+1].m_State == 1) numLive +=1;
				if (m_Cells[1][cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[1][cellY].m_State == 1) numLive +=1;
				if (m_Cells[1][cellY+1].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 3){	//	Klein bottle topology
				if (m_Cells[0][cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[0][cellY+1].m_State == 1) numLive +=1;
				if (m_Cells[1][cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[1][cellY].m_State == 1) numLive +=1;
				if (m_Cells[1][cellY+1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][m_Size-cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][m_Size-cellY].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][m_Size-cellY+1].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 4){	//	Mobius strip topology
				if (m_Cells[0][cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[0][cellY+1].m_State == 1) numLive +=1;
				if (m_Cells[1][cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[1][cellY].m_State == 1) numLive +=1;
				if (m_Cells[1][cellY+1].m_State == 1) numLive +=1;
			}
			else{	//	square topology
				if (m_Cells[0][cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[0][cellY+1].m_State == 1) numLive +=1;
				if (m_Cells[1][cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[1][cellY].m_State == 1) numLive +=1;
				if (m_Cells[1][cellY+1].m_State == 1) numLive +=1;
			}
		}
	}
	else if (cellX == m_Size-1){
		if (cellY == 0){	//	top left
			//	check boundary conditions
			if (m_Boundary == 0){	//	sphere topology
				if (m_Cells[m_Size-1][1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][0].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][1].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 1){	//	torus topology
				if (m_Cells[m_Size-1][1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][0].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[0][0].m_State == 1) numLive +=1;
				if (m_Cells[0][1].m_State == 1) numLive +=1;
				if (m_Cells[0][m_Size-1].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 2){	//	cylinder topology == 1) numLive +=1;
				if (m_Cells[m_Size-1][1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][0].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][m_Size-1].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 3){	//	Klein bottle topology
				if (m_Cells[m_Size-1][1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][0].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[0][0].m_State == 1) numLive +=1;
				if (m_Cells[0][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[0][m_Size-1].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 4){	//	Mobius strip topologyv
				if (m_Cells[m_Size-1][1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][0].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][1].m_State == 1) numLive +=1;
				if (m_Cells[1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[0][m_Size-1].m_State == 1) numLive +=1;
			}
			else{	//	square topology
				if (m_Cells[m_Size-1][1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][0].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][1].m_State == 1) numLive +=1;
			}
		}
		else if (cellY == m_Size - 1){
			if (m_Boundary == 0){	//	sphere topology
				if (m_Cells[m_Size-1][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][m_Size-1].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 1){	//	torus topology
				if (m_Cells[m_Size-1][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][0].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][0].m_State == 1) numLive +=1;
				if (m_Cells[0][0].m_State == 1) numLive +=1;
				if (m_Cells[0][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[0][m_Size-1].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 2){	//	cylinder topology
				if (m_Cells[m_Size-1][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][m_Size-1].m_State  == 1) numLive +=1;
				if (m_Cells[m_Size-1][0].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][0].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 3){	//	Klein bottle topology
				if (m_Cells[m_Size-1][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][0].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][0].m_State == 1) numLive +=1;
				if (m_Cells[0][0].m_State == 1) numLive +=1;
				if (m_Cells[0][1].m_State == 1) numLive +=1;
				if (m_Cells[0][m_Size-1].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 4){	//	Mobius strip topology
				if (m_Cells[m_Size-1][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][m_Size-1].m_State  == 1) numLive +=1;
				if (m_Cells[1][0].m_State == 1) numLive +=1;
				if (m_Cells[0][0].m_State == 1) numLive +=1;
			}
			else{	//	square topology
				if (m_Cells[m_Size-1][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][m_Size-2].m_State  == 1) numLive +=1;
				if (m_Cells[m_Size-2][m_Size-1].m_State == 1) numLive +=1;
			}
		}
		else{
			if (m_Boundary == 0){	//	sphere topology
				if (m_Cells[m_Size-1][cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][cellY+1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][cellY].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][cellY+1].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 1){	//	torus topology
				if (m_Cells[m_Size-1][cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][cellY+1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][cellY].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][cellY+1].m_State == 1) numLive +=1;
				if (m_Cells[0][cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[0][cellY].m_State == 1) numLive +=1;
				if (m_Cells[0][cellY+1].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 2){	//	cylinder topology
				if (m_Cells[m_Size-1][cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][cellY+1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][cellY].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][cellY+1].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 3){	//	Klein bottle topology
				if (m_Cells[m_Size-1][cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][cellY+1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][cellY].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][cellY+1].m_State == 1) numLive +=1;
				if (m_Cells[0][m_Size-cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[0][m_Size-cellY].m_State == 1) numLive +=1;
				if (m_Cells[0][m_Size-cellY+1].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 4){	//	Mobius strip topology
				if (m_Cells[m_Size-1][cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][cellY+1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][cellY].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][cellY+1].m_State == 1) numLive +=1;
			}
			else{	//	square topology
				if (m_Cells[m_Size-1][cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-1][cellY+1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][cellY-1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][cellY].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-2][cellY+1].m_State == 1) numLive +=1;
			}
		}
	}
	else{	//sides
		if (cellY == 0){	//	top left
			//	check boundary conditions
			if (m_Boundary == 0){	//	sphere topology
				if (m_Cells[cellX][1].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][0].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][1].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][0].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][1].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 1){	//	torus topology
				if (m_Cells[cellX][1].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][0].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][1].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][0].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][1].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[cellX][m_Size-1].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 2){	//	cylinder topology
				if (m_Cells[cellX][1].m_State  == 1) numLive +=1;
				if (m_Cells[cellX-1][0].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][1].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][0].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][1].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[cellX][m_Size-1].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 3){	//	Klein bottle topology
				if (m_Cells[cellX][1].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][0].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][1].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][0].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][1].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[cellX][m_Size-1].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 4){	//	Mobius strip topology
				if (m_Cells[cellX][1].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][0].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][1].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][0].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-cellX-1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-cellX+1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-cellX][m_Size-1].m_State == 1) numLive +=1;
			}
			else{	//	square topology
				if (m_Cells[cellX][1].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][0].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][1].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][0].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][1].m_State == 1) numLive +=1;
			}
		}
		else if (cellY == m_Size - 1){
			if (m_Boundary == 0){	//	sphere topology
				if (m_Cells[cellX][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][m_Size-2].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 1){	//	torus topology
				if (m_Cells[cellX][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][0].m_State == 1) numLive +=1;
				if (m_Cells[cellX][0].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][0].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 2){	//	cylinder topology
				if (m_Cells[cellX][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][0].m_State == 1) numLive +=1;
				if (m_Cells[cellX][0].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][0].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 3){	//	Klein bottle topology
				if (m_Cells[cellX][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][0].m_State == 1) numLive +=1;
				if (m_Cells[cellX][0].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][0].m_State == 1) numLive +=1;
			}
			else if (m_Boundary == 4){	//	Mobius strip topology
				if (m_Cells[cellX][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-cellX-1][0].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-cellX][0].m_State == 1) numLive +=1;
				if (m_Cells[m_Size-cellX+1][0].m_State == 1) numLive +=1;
			}
			else{	//	square topology
				if (m_Cells[cellX][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[cellX-1][m_Size-2].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][m_Size-1].m_State == 1) numLive +=1;
				if (m_Cells[cellX+1][m_Size-2].m_State == 1) numLive +=1;
			}
		}
		else{
			if (m_Cells[cellX][cellY+1].m_State == 1) numLive +=1;
			if (m_Cells[cellX][cellY-1].m_State == 1) numLive +=1;
			if (m_Cells[cellX+1][cellY-1].m_State == 1) numLive +=1;
			if (m_Cells[cellX+1][cellY].m_State == 1) numLive +=1;
			if (m_Cells[cellX+1][cellY+1].m_State == 1) numLive +=1;
			if (m_Cells[cellX-1][cellY-1].m_State == 1) numLive +=1;
			if (m_Cells[cellX-1][cellY].m_State == 1) numLive +=1;
			if (m_Cells[cellX-1][cellY+1].m_State == 1) numLive +=1;
		}
	}
	return currentCell + numLive;
}
//	updating cells
void Automata::findOneDimensionalUpdateRule(){
	//	check for num states
	if (m_NumStates == 2){
		if (m_Type == 0){
			findOneDimensionalUpdateRule_2State();
		}
	}
	else if (m_NumStates == 3){
		if (m_Type == 1){
			findOneDimensionalUpdateRule_3State2();
		}
	}
}

void Automata::findOneDimensionalUpdateRule_2State(){
	std::vector<int> tempUpdateRule{0,0,0,0,0,0,0,0};
	int tempDivisor = m_Rule;
	for (int i = 7; i >= 0; i--){
		if (tempDivisor & 1){
			tempUpdateRule[i] = 1;
		}
		else{
			tempUpdateRule[i] = 0;
		}
		tempDivisor >>=1;
	}
	m_UpdateRule = tempUpdateRule;
}

//Totalistic rule for 1st order 3 states
//	3^6 + 3^5 + 3^4 + 3^3 + 3^2 + 3 + 1
void Automata::findOneDimensionalUpdateRule_3State2(){
	std::vector<int> tempUpdateRules{0,0,0,0,0,0,0};
	int tempDivisor = m_Rule;
	for (int i = 6; i >=0; i--){
		if (tempDivisor % 3 != 0){
			tempUpdateRules[i] = (tempDivisor % 3);

		}
		else{

			tempUpdateRules[i] = 0;
		}
		tempDivisor /= 3;
	}
	std::vector<int> newUpdateRules;
	for (int i = 6; i >=0; i--){
		newUpdateRules.push_back(tempUpdateRules[i]);
	}
	m_UpdateRule = newUpdateRules;
}

void Automata::findTwoDimensionalUpdateRule(){
	if (m_Type == 0){
		findTwoDimensionalvonNeumannUpdateRule_2State();
	}
	else if (m_Type == 1){
		findTwoDimensionalvonNeumannUpdateRule_2State2();
	}
	else if (m_Type == 2){
		findTwoDimensionalMooreUpdateRule_2State2();
	}
}

void Automata::findTwoDimensionalvonNeumannUpdateRule_2State(){
	std::vector<int> tempUpdateRule{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int tempDivisor = m_Rule;
	for (int i = 31; i >= 0; i--){
		if (tempDivisor & 1){
			tempUpdateRule[i] = 1;
		}
		else{
			tempUpdateRule[i] = 0;
		}
		tempDivisor >>=1;
	}
	m_UpdateRule = tempUpdateRule;
}

void Automata::findTwoDimensionalvonNeumannUpdateRule_2State2(){
	std::vector<int> tempUpdateRule{0,0,0,0,0,0,0,0,0,0};
	int tempDivisor = m_Rule;
	for (int i = 9; i >= 0; i--){
		if (tempDivisor & 1){
			tempUpdateRule[i] = 1;
		}
		else{
			tempUpdateRule[i] = 0;
		}
		tempDivisor >>=1;
	}
	m_UpdateRule = tempUpdateRule;
}

void Automata::findTwoDimensionalMooreUpdateRule_2State2(){
	std::vector<int> tempUpdateRule{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int tempDivisor = m_Rule;
	for (int i = 17; i >= 0; i--){
		if (tempDivisor & 1){
			tempUpdateRule[i] = 1;
		}
		else{
			tempUpdateRule[i] = 0;
		}
		tempDivisor >>=1;
	}
	std::vector<int> newUpdateRules;
	for (int i = 17; i >=0; i--){
		newUpdateRules.push_back(tempUpdateRule[i]);
	}
	m_UpdateRule = newUpdateRules;
}

void Automata::findTwoDimensionalMooreUpdateRule_NState2(std::string rule){
	//	This should be in B/S/n format
	std::vector<std::string> results;
	for (int i = 0; i < rule.size(); i++){
		std::stringstream ss;
		std::string s;
		ss << rule[i];
		ss >> s;
		results.push_back(s);
	}
	m_Rule = 0;
	//	Find B and S values
	std::string N;
	for (int i = 0; i < results.size(); i++){
		if (results[i] == "B"){
			while (results[i+1] != "/"){
				m_Rule += pow(2, atoi(results[i+1].c_str()));
				i++;
			}
		}
		else if (results[i] == "S"){
			while (results[i+1] != "/"){
				m_Rule += pow(2, (atoi(results[i+1].c_str()) + 9));
				i++;
			}
		}
		else if (results[i]=="/"){}
		else{
			N += results[i];
		}
	}
	m_NumStates = atoi(N.c_str());
}

void Automata::updateOneDimensionalCells(){
	if (m_NumStates == 2){
		if (m_Type == 0){
			updateOneDimensionalCells_2State();
		}
	}
	else if (m_NumStates == 3){
		if (m_Type == 1){
			updateOneDimensionalCells_3State2();
		}
	}
}

void Automata::updateOneDimensionalCells_2State(){
	std::vector<std::vector<Cell> > cellCopy = m_Cells;
	for (int j = 0; j < m_Size; j++){
		//std::cout << cellCopy[j].m_State << std::endl;
		//std::cout << findOneDimensionalState(j) << std::endl;
		//std::cout << m_UpdateRule[findOneDimensionalState(j)];
		cellCopy[0][j].m_State = m_UpdateRule[findOneDimensionalState(j)];
	}
	m_Cells = cellCopy;
}

void Automata::updateOneDimensionalCells_3State2(){
	std::vector<std::vector<Cell> > cellCopy = m_Cells;
	for (int j = 0; j < m_Size; j++){
		//std::cout << cellCopy[0][j].m_State << std::endl;
		//std::cout << findOneDimensionalState3States2(j) << std::endl;
		//std::cout << m_UpdateRule[findOneDimensionalState3States2(j)] << std::endl;
		cellCopy[0][j].m_State = m_UpdateRule[findOneDimensionalState_3State2(j)];
	}
	m_Cells = cellCopy;
}

void Automata::updateTwoDimensionalCells(){
	if (m_NumStates == 2){
		if (m_Type == 0){
			updateTwoDimensionalvonNeumannCells_2State();
		}
		else if (m_Type == 1){
			updateTwoDimensionalvonNeumannCells_2State2();
		}
		else if (m_Type == 2){
			updateTwoDimensionalMooreCells_2State2();
		}
	}
	else{
		updateTwoDimensionalMooreCells_NState2();
	}
}

void Automata::updateTwoDimensionalvonNeumannCells_2State(){
	std::vector<std::vector<Cell> > cellCopy = m_Cells;
	for (int i = 0; i < m_Size; i++){
		for (int j = 0; j < m_Size; j++){
			//std::cout << cellCopy[j].m_State << std::endl;
			//std::cout << findOneDimensionalState(j) << std::endl;
			//std::cout << m_UpdateRule[findOneDimensionalState(j)];
			cellCopy[i][j].m_State = m_UpdateRule[findTwoDimensionalvonNeumannState_2State(i,j)];
		}
	}
	m_Cells = cellCopy;
}

void Automata::updateTwoDimensionalvonNeumannCells_2State2(){
	std::vector<std::vector<Cell> > cellCopy = m_Cells;
	for (int i = 0; i < m_Size; i++){
		for (int j = 0; j < m_Size; j++){
			//std::cout << cellCopy[j].m_State << std::endl;
			//std::cout << findOneDimensionalState(j) << std::endl;
			//std::cout << m_UpdateRule[findOneDimensionalState(j)];
			cellCopy[i][j].m_State = m_UpdateRule[findTwoDimensionalvonNeumannState_2State2(i,j)];
		}
	}
	m_Cells = cellCopy;
}

void Automata::updateTwoDimensionalMooreCells_2State2(){
	std::vector<std::vector<Cell> > cellCopy = m_Cells;
	for (int i = 0; i < m_Size; i++){
		for (int j = 0; j < m_Size; j++){
			//std::cout << cellCopy[i][j].m_State <<",";
			//std::cout << findTwoDimensionalMooreState_2State2(i,j) << ",";
			//std::cout << m_UpdateRule[findTwoDimensionalMooreState_2State2(i,j)] << std::endl;
			cellCopy[i][j].m_State = m_UpdateRule[findTwoDimensionalMooreState_2State2(i,j)];
		}
	}
	m_Cells = cellCopy;
}
void Automata::updateTwoDimensionalMooreCells_NState2(){
	std::vector<std::vector<Cell> > cellCopy = m_Cells;
	for (int i = 0; i < m_Size; i++){
		for (int j = 0; j < m_Size; j++){
			//std::cout << cellCopy[i][j].m_State <<",";
			//std::cout << findTwoDimensionalMooreState_2State2(i,j) << ",";
			//std::cout << m_UpdateRule[findTwoDimensionalMooreState_2State2(i,j)] << std::endl;
			int rule =  m_UpdateRule[findTwoDimensionalMooreState_NState2(i,j)];
			if (cellCopy[i][j].m_State == 0){
				if (rule == 1) cellCopy[i][j].m_State = 1;
			}
			else if (cellCopy[i][j].m_State == 1){
				if (rule == 1){}
				else cellCopy[i][j].m_State += 1;
			}
			else{
				if (cellCopy[i][j].m_State == m_NumStates - 1) cellCopy[i][j].m_State = 0;
				else cellCopy[i][j].m_State += 1;
			}
		}
	}
	m_Cells = cellCopy;
}

//	printing
void Automata::printCells(){
	for (int j = 0; j < m_Cells.size(); j++){
		for (int i = 0; i < m_Cells[j].size(); i++){
			std::cout << m_Cells[j][i].m_State << " ";
		}
		std::cout << std::endl;
	}
}

void Automata::displayOneDimensionalCells_2State(){
//	for (int i = 0; i < 100; i++){
//			std::cout << std::endl;
//		}
		std::cout << "|";
		for (int j = 0; j < m_Size; j++){
			if (m_Cells[0][j].m_State == 0){
				std::cout << " ";
			}
			else{
				std::cout << "o";
			}
		}
		std::cout << "|" << std::endl;
}

void Automata::displayOneDimensionalCells_3State(){
//	for (int i = 0; i < 100; i++){
//			std::cout << std::endl;
//		}
		std::cout << "|";
		for (int j = 0; j < m_Size; j++){
			if (m_Cells[0][j].m_State == 0){
				std::cout << " ";
			}
			else if (m_Cells[0][j].m_State == 1){
				std::cout << "*";
			}
			else{
				std::cout << "o";
			}
		}
		std::cout << "|" << std::endl;
}

void Automata::displayTwoDimensionalCells_2State(){
	for (int i = 0; i < 100; i++){
		std::cout << std::endl;
	}
	for (int i = 0; i < m_Size; i++){
		std::cout << "|";
		for (int j = 0; j < m_Size; j++){
			if (m_Cells[i][j].m_State == 0){
				std::cout << " ";
			}
			else{
				std::cout << "o";
			}
		}
		std::cout << "|" << std::endl;
	}
}

//	set cell values
void Automata::setCells(std::vector<std::vector<int> > states){
	for (int i = 0; i < states.size(); i++){
		for (int j = 0; j < states[i].size(); j++){
			m_Cells[i][j].m_State = states[i][j];
		}
	}
}

//	initializers
void Automata::initializeOneDimensionalEmptyCells(){
	findOneDimensionalUpdateRule();
	std::vector<Cell> tempCells;
	for (int i = 0; i < m_Size; i++){
		tempCells.push_back(Cell(0, m_NumStates));
	}
	m_Cells.push_back(tempCells);
}

void Automata::initializeOneDimensionalCells(){

	findOneDimensionalUpdateRule();
	//	check for existence of dimension, type, size, and density
	if (m_Dim == 0){
		std::cout << "ERROR! Dimension of manifold must be 1 or 2 dimensional! : m_Type = " << m_Type << std::endl;
		return;
	}
	else if (m_Size <= 0){
		std::cout << "ERROR! Size of the space should be at least 1! : m_Size = " << m_Size << std::endl;
	}
	else if (m_Density <= 0.0){
		std::cout << "ERROR! Density must be greater than 0! : m_Density = " << m_Density << std::endl;
	}
	else{
		initializeOneDimensionalEmptyCells();
		if (m_Dim == 1){
			for (int i = 0; i < m_Size; i++){
				if ((float)rand()/RAND_MAX <= m_Density){
					m_Cells[0][i].m_State = 1;
				}
				else{
					m_Cells[0][i].m_State = 0;
				}
			}
		}
	}
}

void Automata::initializeTwoDimensionalEmptyCells(){
	findTwoDimensionalUpdateRule();
	for (int j = 0; j < m_Size; j++){
		std::vector<Cell> tempCells;
		if (m_Type == 2){
			for (int i = 0; i < m_Size; i++){
				tempCells.push_back(Cell(0, m_NumStates));
			}
		}
		m_Cells.push_back(tempCells);
	}
}
void Automata::initializeTwoDimensionalCells(){
	findTwoDimensionalUpdateRule();
	//	check for existence of type, size, and density
	if (m_Dim == 0){
		std::cout << "ERROR! Dimension of manifold must be 1 or 2 dimensional! : m_Type = " << m_Type << std::endl;
		return;
	}
	else if (m_Size <= 0){
		std::cout << "ERROR! Size of the space should be at least 1! : m_Size = " << m_Size << std::endl;
	}
	else if (m_Density <= 0.0){
		std::cout << "ERROR! Density must be greater than 0! : m_Density = " << m_Density << std::endl;
	}
	else{
		initializeTwoDimensionalEmptyCells();
		if (m_Type == 2){
			for (int j = 0; j < m_Size; j++){
				for (int i = 0; i < m_Size; i++){
					if ((float)rand()/RAND_MAX <= m_Density){
						m_Cells[j][i].m_State = 1;
					}
					else{
						m_Cells[j][i].m_State = 0;
					}
				}
			}
		}
	}
}

std::vector <std::vector <int> > Automata::generateOneDimensionalSequence(){
	if (m_NumStates == 2){
		if (m_Type == 0){
			return generateOneDimensionalSequence_2State();
		}
	}
	else if (m_NumStates == 3){
		if (m_Type == 1){
			return generateOneDimensionalSequence_3State2();
		}
	}
}
//	generators
std::vector <std::vector <int> > Automata::generateOneDimensionalSequence_2State(){
	//	check for necessary conditions
	std::vector <std::vector <int> > sequence;
	for (int i = 0; i < m_Time; i++){
		std::vector <int> tempCells;
		for (int j = 0; j < m_Size; j++){
			tempCells.push_back(m_Cells[0][j].m_State);
		}
		sequence.push_back(tempCells);
		updateOneDimensionalCells();
	}
	return sequence;
}

std::vector <std::vector <int> > Automata::generateOneDimensionalSequence_3State2(){
	//	check for necessary conditions
	std::vector <std::vector <int> > sequence;
	for (int i = 0; i < m_Time; i++){
		std::vector <int> tempCells;
		for (int j = 0; j < m_Size; j++){
			tempCells.push_back(m_Cells[0][j].m_State);
		}
		sequence.push_back(tempCells);
		updateOneDimensionalCells_3State2();
	}
	return sequence;
}

std::vector<std::vector <std::vector <int>  > > Automata::generateTwoDimensionalSequence(){
		return generateTwoDimensionalSequence_2State();
}


std::vector<std::vector <std::vector <int>  > > Automata::generateTwoDimensionalSequence_2State(){
	//	check for necessary conditions
	std::vector <std::vector <std::vector <int> > > sequence;
	for (int i = 0; i < m_Time; i++){
		std::vector <std::vector <int> > tempCells;
		for (int k = 0; k < m_Size; k++){
			std::vector <int> temp;
			for (int j = 0; j < m_Size; j++){
				temp.push_back(m_Cells[k][j].m_State);
			}
			tempCells.push_back(temp);
		}
		sequence.push_back(tempCells);
		updateTwoDimensionalCells();
	}
	return sequence;
}

//	save sequence to file
void Automata::saveOneDimensionalSequenceToFile(std::vector <std::vector <int> > sequence, const char * fileName){
	std::ofstream myfile;
	myfile.open(fileName);
	for (int i = 0; i < sequence.size(); i++){
		for (int j = 0; j < sequence[i].size(); j++){
			myfile << sequence[i][j];
			if (j != sequence[i].size() - 1){
				myfile << ",";
			}
		}
		myfile << "\n";
	}
	myfile.close();
}

void Automata::saveTwoDimensionalSequenceToFile(std::vector <std::vector <std::vector <int> > > sequence, const char * fileName){
	std::ofstream myfile;
	myfile.open(fileName);
	for (int i = 0; i < sequence.size(); i++){
		for (int j = 0; j < m_Size; j++){
			for (int k = 0; k < m_Size; k++){
				myfile << sequence[i][j][k];
				if (j != m_Size - 1){
					myfile << ",";
				}
			}
		}
		myfile << "\n";
	}
	myfile.close();
}

std::vector<std::vector<int> > Automata::getState(){
	std::vector<std::vector<int> > state;
	for (int i = 0; i < m_Cells.size(); i++){
		std::vector<int> row;
		for (int j = 0; j < m_Cells[i].size(); j++){
			row.push_back(m_Cells[i][j].m_State);
		}
		state.push_back(row);
	}
	return state;
}

int main(){

	srand(time(NULL));

//	//	initial state
//	std::vector<int> initialState;
//	for (int i = 0; i < 51; i++){
//		initialState.push_back(0);
//	}
//	initialState[25] = 1;
//
//	std::vector<std::vector<int> > initial;
//	initial.push_back(initialState);
//	Automata test(1, 51, 3, 0, 1086, 1, .4, 500);
//	test.initializeOneDimensionalEmptyCells();
//	test.setCells(initial);
//	test.findOneDimensionalUpdateRule();
//	//test.printCells();
//	test.displayOneDimensionalCells_3State();
//	//std::vector <std::vector <int> > sequence = test.generateOneDimensionalSequence3States2();
//	//test.saveSequenceToFile(sequence, "test.csv");
//	for (int i = 0; i < 25; i++){
//		test.updateOneDimensionalCells();
//		test.displayOneDimensionalCells_3State();
//	}

	// Automata test(2, 50, 2, 1, 6152, 2, .75, 100);
	// test.initializeTwoDimensionalCells();
	// for (int i = 0; i < 25; i++){
	// 	test.updateTwoDimensionalCells();
	// 	usleep(100000);
	// 	test.displayTwoDimensionalCells_2State();
	// }
	// 
	// int width = 36;
	// int height = 54;
	//
	// std::vector<int> label = ConnectedComponents(array, width, height);
	//
	// int column_counter = 1;
	//
	// for(int n : label) {
	// 	if (column_counter % width == 0){
	// 		std::cout << n << '\n';
	// 		// std::cout << "HERE";
	// 	} else {
	// 		std::cout << n;
	// 	}
	// 	column_counter++;
	// }

	return 0;

}
