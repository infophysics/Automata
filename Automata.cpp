/*
 * Automata.cpp
 *
 *  Created on: Sep 5, 2018
 *      Author: ncarrara
 */

#include "Automata.h"
#include <stdio.h>


//	Default constructor
Automata::Automata() : m_Type(0), m_Size(0), m_Boundary(-1), m_Rule(-1), m_Density(0), m_Time(0) {}
Automata::~Automata() {}
//	Various constructors
Automata::Automata(int type) : m_Type(type), m_Size(0), m_Boundary(-1), m_Rule(-1), m_Density(0), m_Time(0) {}
Automata::Automata(int type, int size) : m_Type(type), m_Size(size), m_Boundary(-1), m_Rule(-1), m_Density(0), m_Time(0) {initializeEmptyCells();}
Automata::Automata(int type, int size, int boundary) : m_Type(type), m_Size(size), m_Boundary(boundary), m_Rule(-1), m_Density(0), m_Time(0) {initializeEmptyCells();}
Automata::Automata(int type, int size, int boundary, int rule) : m_Type(type), m_Size(size), m_Boundary(boundary), m_Rule(rule), m_Density(0), m_Time(0) {initializeEmptyCells();}
Automata::Automata(int type, int size, int boundary, int rule, float density) : m_Type(type), m_Size(size), m_Boundary(boundary), m_Rule(rule), m_Density(density), m_Time(0) {initializeCells();}
Automata::Automata(int type, int size, int boundary, int rule, float density, int time) : m_Type(type), m_Size(size), m_Boundary(boundary), m_Rule(rule), m_Density(density), m_Time(time){initializeCells();}


//	state determination
int Automata::findOneDimensionalState(int cell){
	//	check for boundary cells
	if (cell == 0){
		//	check for boundary conditions
		if (m_Boundary == 0){	//	circle topology
			if (m_Cells[cell].m_State == 1){
				if (m_Cells[m_Size-1].m_State == 1){
					if (m_Cells[cell+1].m_State == 1){
						return 0;
					}
					else{
						return 1;
					}
				}
				else{
					if (m_Cells[cell+1].m_State == 1){
						return 4;
					}
					else{
						return 5;
						std::cout << "HERE" << std::endl;
					}
				}
			}
			else{
				if (m_Cells[m_Size-1].m_State == 1){
					if (m_Cells[cell+1].m_State == 1){
						return 2;
					}
					else{
						return 3;
					}
				}
				else{
					if (m_Cells[cell+1].m_State == 1){
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
			if (m_Cells[cell].m_State == 1){
				if (m_Cells[cell-1].m_State == 1){
					if (m_Cells[0].m_State == 1){
						return 0;
					}
					else{
						return 1;
					}
				}
				else{
					if (m_Cells[0].m_State == 1){
						return 4;
					}
					else{
						return 5;
					}
				}
			}
			else{
				if (m_Cells[cell-1].m_State == 1){
					if (m_Cells[0].m_State == 1){
						return 2;
					}
					else{
						return 3;
					}
				}
				else{
					if (m_Cells[0].m_State == 1){
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
			if (m_Cells[cell].m_State == 1){
				if (m_Cells[cell-1].m_State == 1){
					if (m_Cells[cell+1].m_State == 1){
						return 0;
					}
					else{
						return 1;
					}
				}
				else{
					if (m_Cells[cell+1].m_State == 1){
						return 4;
					}
					else{
						return 5;
					}
				}
			}
			else{
				if (m_Cells[cell-1].m_State == 1){
					if (m_Cells[cell+1].m_State == 1){
						return 2;
					}
					else{
						return 3;
					}
				}
				else{
					if (m_Cells[cell+1].m_State == 1){
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

//int Automata::findTwoDimensionalState(int cellX, int cellY){
//	//	check for boundary cells
//	if (cellX == 0){	//	top of grid
//		if (cellY == 0){	//	top left
//			//	check boundary conditions
//			if (m_Boundary == 0){	//	sphere topology
//				return m_Cells[0][1] + m_Cells[1][0] + m_Cells[1][1];
//			}
//			else if (m_Boundary == 1){	//	torus topology
//				return m_Cells[0][1] + m_Cells[1][0] + m_Cells[1][1] + m_Cells[0][m_Size-1] + m_Cells[1][m_Size-1] + m_Cells[m_Size-1][0] + m_Cells[m_Size-1][1] + m_Cells[m_Size-1][m_Size-1];
//			}
//			else if (m_Boundary == 2){	//	cylinder topology
//				return m_Cells[0][1] + m_Cells[1][0] + m_Cells[1][1] + m_Cells[0][m_Size-1] + m_Cells[1][m_Size-1];
//			}
//			else if (m_Boundary == 3){	//	Klein bottle topology
//				return m_Cells[0][1] + m_Cells[1][0] + m_Cells[1][1] + m_Cells[0][m_Size-1] + m_Cells[1][m_Size-1] + m_Cells[m_Size-1][0] + m_Cells[m_Size-1][m_Size-2] + m_Cells[m_Size-1][m_Size-1];
//			}
//			else if (m_Boundary == 4){	//	Mobius strip topology
//				return m_Cells[0][1] + m_Cells[1][0] + m_Cells[1][1] + m_Cells[m_Size-2][m_Size-1] + m_Cells[m_Size-1][m_Size-1];
//			}
//			else{	//	square topology
//				return m_Cells[0][1] + m_Cells[1][0] + m_Cells[1][1];
//			}
//		}
//		else if (cellY == m_Size - 1){
//			if (m_Boundary == 0){	//	sphere topology
//				return m_Cells[0][m_Size-2] + m_Cells[1][m_Size-2] + m_Cells[1][m_Size-1];
//			}
//			else if (m_Boundary == 1){	//	torus topology
//				return m_Cells[0][m_Size-2] + m_Cells[1][m_Size-2] + m_Cells[1][m_Size-1] + m_Cells[0][0] + m_Cells[1][0] + m_Cells[m_Size-1][0] + m_Cells[m_Size-1][m_Size-2] + m_Cells[m_Size-1][m_Size-1];
//			}
//			else if (m_Boundary == 2){	//	cylinder topology
//				return m_Cells[0][m_Size-2] + m_Cells[1][m_Size-2] + m_Cells[1][m_Size-1] + m_Cells[0][0] + m_Cells[1][0];
//			}
//			else if (m_Boundary == 3){	//	Klein bottle topology
//				return m_Cells[0][m_Size-2] + m_Cells[1][m_Size-2] + m_Cells[1][m_Size-1] + m_Cells[0][0] + m_Cells[1][0] + m_Cells[m_Size-1][0] + m_Cells[m_Size-1][1] + m_Cells[m_Size-1][m_Size-1];
//			}
//			else if (m_Boundary == 4){	//	Mobius strip topology
//				return m_Cells[0][m_Size-2] + m_Cells[1][m_Size-2] + m_Cells[1][m_Size-1] + m_Cells[m_Size-2][0] + m_Cells[m_Size-1][0];
//			}
//			else{	//	square topology
//				return m_Cells[0][m_Size-2] + m_Cells[1][m_Size-2] + m_Cells[1][m_Size-1];
//			}
//		}
//		else{
//			if (m_Boundary == 0){	//	sphere topology
//				return m_Cells[0][cellY-1] + m_Cells[0][cellY+1] + m_Cells[1][cellY-1] + m_Cells[1][cellY] + m_Cells[1][cellY+1];
//			}
//			else if (m_Boundary == 1){	//	torus topology
//				return m_Cells[0][cellY-1] + m_Cells[0][cellY+1] + m_Cells[1][cellY-1] + m_Cells[1][cellY] + m_Cells[1][cellY+1] + m_Cells[m_Size-1][cellY-1] + m_Cells[m_Size-1][cellY] + m_Cells[m_Size-1][cellY+1];
//			}
//			else if (m_Boundary == 2){	//	cylinder topology
//				return m_Cells[0][cellY-1] + m_Cells[0][cellY+1] + m_Cells[1][cellY-1] + m_Cells[1][cellY] + m_Cells[1][cellY+1];
//			}
//			else if (m_Boundary == 3){	//	Klein bottle topology
//				return m_Cells[0][cellY-1] + m_Cells[0][cellY+1] + m_Cells[1][cellY-1] + m_Cells[1][cellY] + m_Cells[1][cellY+1] + m_Cells[m_Size-1][m_Size-cellY-1] + m_Cells[m_Size-1][m_Size-cellY] + m_Cells[m_Size-1][m_Size-cellY+1];
//			}
//			else if (m_Boundary == 4){	//	Mobius strip topology
//				return m_Cells[0][cellY-1] + m_Cells[0][cellY+1] + m_Cells[1][cellY-1] + m_Cells[1][cellY] + m_Cells[1][cellY+1];
//			}
//			else{	//	square topology
//				return m_Cells[0][cellY-1] + m_Cells[0][cellY+1] + m_Cells[1][cellY-1] + m_Cells[1][cellY] + m_Cells[1][cellY+1];
//			}
//		}
//	}
//	else if (cellX == m_Size-1){
//		if (cellY == 0){	//	top left
//			//	check boundary conditions
//			if (m_Boundary == 0){	//	sphere topology
//				return m_Cells[m_Size-1][1] + m_Cells[m_Size-2][0] + m_Cells[m_Size-2][1];
//			}
//			else if (m_Boundary == 1){	//	torus topology
//				return m_Cells[m_Size-1][1] + m_Cells[m_Size-2][0] + m_Cells[m_Size-2][1] + m_Cells[m_Size-1][m_Size-1] + m_Cells[m_Size-2][m_Size-1] + m_Cells[0][0] + m_Cells[0][1] + m_Cells[0][m_Size-1];
//			}
//			else if (m_Boundary == 2){	//	cylinder topology
//				return m_Cells[m_Size-1][1] + m_Cells[m_Size-2][0] + m_Cells[m_Size-2][1] + m_Cells[m_Size-1][m_Size-1] + m_Cells[m_Size-2][m_Size-1];
//			}
//			else if (m_Boundary == 3){	//	Klein bottle topology
//				return m_Cells[m_Size-1][1] + m_Cells[m_Size-2][0] + m_Cells[m_Size-2][1] + m_Cells[m_Size-1][m_Size-1] + m_Cells[m_Size-2][m_Size-1] + m_Cells[0][0] + m_Cells[0][m_Size-2] + m_Cells[0][m_Size-1];
//			}
//			else if (m_Boundary == 4){	//	Mobius strip topology
//				return m_Cells[m_Size-1][1] + m_Cells[m_Size-2][0] + m_Cells[m_Size-2][1] + m_Cells[1][m_Size-1] + m_Cells[0][m_Size-1];
//			}
//			else{	//	square topology
//				return m_Cells[m_Size-1][1] + m_Cells[m_Size-2][0] + m_Cells[m_Size-2][1];
//			}
//		}
//		else if (cellY == m_Size - 1){
//			if (m_Boundary == 0){	//	sphere topology
//				return m_Cells[m_Size-1][m_Size-2] + m_Cells[m_Size-2][m_Size-2] + m_Cells[m_Size-2][m_Size-1];
//			}
//			else if (m_Boundary == 1){	//	torus topology
//				return m_Cells[m_Size-1][m_Size-2] + m_Cells[m_Size-2][m_Size-2] + m_Cells[m_Size-2][m_Size-1] + m_Cells[m_Size-1][0] + m_Cells[m_Size-2][0] + m_Cells[0][0] + m_Cells[0][m_Size-2] + m_Cells[0][m_Size-1];
//			}
//			else if (m_Boundary == 2){	//	cylinder topology
//				return m_Cells[m_Size-1][m_Size-2] + m_Cells[m_Size-2][m_Size-2] + m_Cells[m_Size-2][m_Size-1] + m_Cells[m_Size-1][0] + m_Cells[m_Size-2][0];
//			}
//			else if (m_Boundary == 3){	//	Klein bottle topology
//				return m_Cells[m_Size-1][m_Size-2] + m_Cells[m_Size-2][m_Size-2] + m_Cells[m_Size-2][m_Size-1] + m_Cells[m_Size-1][0] + m_Cells[m_Size-2][0] + m_Cells[0][0] + m_Cells[0][1] + m_Cells[0][m_Size-1];
//			}
//			else if (m_Boundary == 4){	//	Mobius strip topology
//				return m_Cells[m_Size-1][m_Size-2] + m_Cells[m_Size-2][m_Size-2] + m_Cells[m_Size-2][m_Size-1] + m_Cells[1][0] + m_Cells[0][0];
//			}
//			else{	//	square topology
//				return m_Cells[m_Size-1][m_Size-2] + m_Cells[m_Size-2][m_Size-2] + m_Cells[m_Size-2][m_Size-1];
//			}
//		}
//		else{
//			if (m_Boundary == 0){	//	sphere topology
//				return m_Cells[m_Size-1][cellY-1] + m_Cells[m_Size-1][cellY+1] + m_Cells[m_Size-2][cellY-1] + m_Cells[m_Size-2][cellY] + m_Cells[m_Size-2][cellY+1];
//			}
//			else if (m_Boundary == 1){	//	torus topology
//				return m_Cells[m_Size-1][cellY-1] + m_Cells[m_Size-1][cellY+1] + m_Cells[m_Size-2][cellY-1] + m_Cells[m_Size-2][cellY] + m_Cells[m_Size-2][cellY+1] + m_Cells[0][cellY-1] + m_Cells[0][cellY] + m_Cells[0][cellY+1];
//			}
//			else if (m_Boundary == 2){	//	cylinder topology
//				return m_Cells[m_Size-1][cellY-1] + m_Cells[m_Size-1][cellY+1] + m_Cells[m_Size-2][cellY-1] + m_Cells[m_Size-2][cellY] + m_Cells[m_Size-2][cellY+1];
//			}
//			else if (m_Boundary == 3){	//	Klein bottle topology
//				return m_Cells[m_Size-1][cellY-1] + m_Cells[m_Size-1][cellY+1] + m_Cells[m_Size-2][cellY-1] + m_Cells[m_Size-2][cellY] + m_Cells[m_Size-2][cellY+1] + m_Cells[0][m_Size-cellY-1] + m_Cells[0][m_Size-cellY] + m_Cells[0][m_Size-cellY+1];
//			}
//			else if (m_Boundary == 4){	//	Mobius strip topology
//				return m_Cells[m_Size-1][cellY-1] + m_Cells[m_Size-1][cellY+1] + m_Cells[m_Size-2][cellY-1] + m_Cells[m_Size-2][cellY] + m_Cells[m_Size-2][cellY+1];
//			}
//			else{	//	square topology
//				return m_Cells[m_Size-1][cellY-1] + m_Cells[m_Size-1][cellY+1] + m_Cells[m_Size-2][cellY-1] + m_Cells[m_Size-2][cellY] + m_Cells[m_Size-2][cellY+1];
//			}
//		}
//	}
//	else{	//sides
//		if (cellY == 0){	//	top left
//			//	check boundary conditions
//			if (m_Boundary == 0){	//	sphere topology
//				return m_Cells[cellX][1] + m_Cells[cellX-1][0] + m_Cells[cellX-1][1] + m_Cells[cellX+1][0] + m_Cells[cellX+1][1];
//			}
//			else if (m_Boundary == 1){	//	torus topology
//				return m_Cells[cellX][1] + m_Cells[cellX-1][0] + m_Cells[cellX-1][1] + m_Cells[cellX+1][0] + m_Cells[cellX+1][1] + m_Cells[cellX-1][m_Size-1] + m_Cells[cellX+1][m_Size-1] + m_Cells[cellX][m_Size-1];
//			}
//			else if (m_Boundary == 2){	//	cylinder topology
//				return m_Cells[cellX][1] + m_Cells[cellX-1][0] + m_Cells[cellX-1][1] + m_Cells[cellX+1][0] + m_Cells[cellX+1][1] + m_Cells[cellX-1][m_Size-1] + m_Cells[cellX+1][m_Size-1] + m_Cells[cellX][m_Size-1];
//			}
//			else if (m_Boundary == 3){	//	Klein bottle topology
//				return m_Cells[cellX][1] + m_Cells[cellX-1][0] + m_Cells[cellX-1][1] + m_Cells[cellX+1][0] + m_Cells[cellX+1][1] + m_Cells[cellX-1][m_Size-1] + m_Cells[cellX+1][m_Size-1] + m_Cells[cellX][m_Size-1];
//			}
//			else if (m_Boundary == 4){	//	Mobius strip topology
//				return m_Cells[cellX][1] + m_Cells[cellX-1][0] + m_Cells[cellX-1][1] + m_Cells[cellX+1][0] + m_Cells[cellX+1][1] + m_Cells[m_Size-cellX-1][m_Size-1] + m_Cells[m_Size-cellX+1][m_Size-1] + m_Cells[m_Size-cellX][m_Size-1];
//			}
//			else{	//	square topology
//				return m_Cells[cellX][1] + m_Cells[cellX-1][0] + m_Cells[cellX-1][1] + m_Cells[cellX+1][0] + m_Cells[cellX+1][1];
//			}
//		}
//		else if (cellY == m_Size - 1){
//			if (m_Boundary == 0){	//	sphere topology
//				return m_Cells[cellX][m_Size-2] + m_Cells[cellX-1][m_Size-1] + m_Cells[cellX-1][m_Size-2] + m_Cells[cellX+1][m_Size-1] + m_Cells[cellX+1][m_Size-2];
//			}
//			else if (m_Boundary == 1){	//	torus topology
//				return m_Cells[cellX][m_Size-2] + m_Cells[cellX-1][m_Size-1] + m_Cells[cellX-1][m_Size-2] + m_Cells[cellX+1][m_Size-1] + m_Cells[cellX+1][m_Size-2] + m_Cells[cellX-1][0] + m_Cells[cellX][0] + m_Cells[cellX+1][0];
//			}
//			else if (m_Boundary == 2){	//	cylinder topology
//				return m_Cells[cellX][m_Size-2] + m_Cells[cellX-1][m_Size-1] + m_Cells[cellX-1][m_Size-2] + m_Cells[cellX+1][m_Size-1] + m_Cells[cellX+1][m_Size-2] + m_Cells[cellX-1][0] + m_Cells[cellX][0] + m_Cells[cellX+1][0];
//			}
//			else if (m_Boundary == 3){	//	Klein bottle topology
//				return m_Cells[cellX][m_Size-2] + m_Cells[cellX-1][m_Size-1] + m_Cells[cellX-1][m_Size-2] + m_Cells[cellX+1][m_Size-1] + m_Cells[cellX+1][m_Size-2] + m_Cells[cellX-1][0] + m_Cells[cellX][0] + m_Cells[cellX+1][0];
//			}
//			else if (m_Boundary == 4){	//	Mobius strip topology
//				return m_Cells[cellX][m_Size-2] + m_Cells[cellX-1][m_Size-1] + m_Cells[cellX-1][m_Size-2] + m_Cells[cellX+1][m_Size-1] + m_Cells[cellX+1][m_Size-2] + m_Cells[m_Size-cellX-1][0] + m_Cells[m_Size-cellX][0] + m_Cells[m_Size-cellX+1][0];
//			}
//			else{	//	square topology
//				return m_Cells[cellX][m_Size-2] + m_Cells[cellX-1][m_Size-1] + m_Cells[cellX-1][m_Size-2] + m_Cells[cellX+1][m_Size-1] + m_Cells[cellX+1][m_Size-2];
//			}
//		}
//		else{
//			return m_Cells[cellX][cellY+1] + m_Cells[cellX][cellY-1] + m_Cells[cellX+1][cellY-1] + m_Cells[cellX+1][cellY] + m_Cells[cellX+1][cellY+1] + m_Cells[cellX-1][cellY-1] + m_Cells[cellX-1][cellY] + m_Cells[cellX-1][cellY+1];
//		}
//	}
//}

//	updating cells
void Automata::findUpdateRule(){
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
	std::cout << std::endl;
}
void Automata::updateOneDimensionalCells(){
	std::vector<Cell> cellCopy = m_Cells;
	for (int j = 0; j < m_Size; j++){
		//std::cout << cellCopy[j].m_State << std::endl;
		//std::cout << findOneDimensionalState(j) << std::endl;
		//std::cout << m_UpdateRule[findOneDimensionalState(j)];
		cellCopy[j].m_State = m_UpdateRule[findOneDimensionalState(j)];
	}
	m_Cells = cellCopy;
}
//void Automata::updateTwoDimensionalCells(){
//
//}


//	printing
void Automata::printCells(){
	for (int i = 0; i < m_Cells.size(); i++){
		std::cout << m_Cells[i].m_State << " ";
	}
	std::cout << std::endl;
}

void Automata::displayOneDimensionalCells(){
//	for (int i = 0; i < 100; i++){
//			std::cout << std::endl;
//		}
		std::cout << "|";
		for (int j = 0; j < m_Size; j++){
			if (m_Cells[j].m_State == 0){
				std::cout << " ";
			}
			else{
				std::cout << "o";
			}
		}
		std::cout << "|" << std::endl;
}


//void Automata::displayTwoDimensionalCells(){
//	for (int i = 0; i < 100; i++){
//		std::cout << std::endl;
//	}
//	for (int i = 0; i < m_Size; i++){
//		std::cout << "|";
//		for (int j = 0; j < m_Size; j++){
//			if (m_Cells[i][j] == 0){
//				std::cout << " ";
//			}
//			else{
//				std::cout << "o";
//			}
//		}
//		std::cout << "|" << std::endl;
//	}
//}

//	set cell values
void Automata::setCells(std::vector<int> states){
	for (int j = 0; j < m_Size; j++){
		m_Cells[j].m_State = states[j];
	}
}

//	initializers
void Automata::initializeEmptyCells(){
	findUpdateRule();
	if (m_Type == 1){
		for (int i = 0; i < m_Size; i++){
			m_Cells.push_back(Cell(0));
		}
	}
}

void Automata::initializeCells(){
	findUpdateRule();
	//	check for existence of type, size, and density
	if (m_Type == 0){
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
		initializeEmptyCells();
		if (m_Type == 1){
			for (int i = 0; i < m_Size; i++){
				if ((float)rand()/RAND_MAX <= m_Density){
					m_Cells[i].m_State = 1;
				}
				else{
					m_Cells[i].m_State = 0;
				}
			}
		}
	}
}
//	initializer with density
void Automata::initializeCells(float density){
	findUpdateRule();
	//	check for existence of type, size
	if (m_Type == 0){
		std::cout << "ERROR! Dimension of manifold must be 1 or 2 dimensional! : m_Type = " << m_Type << std::endl;
		return;
	}
	else if (m_Size <= 0){
		std::cout << "ERROR! Size of the space should be at least 1! : m_Size = " << m_Size << std::endl;
	}
	else{
		if (m_Type == 1){
			for (int i = 0; i < m_Size; i++){
				if ((float)rand()/RAND_MAX <= density){
					m_Cells[i].m_State = 1;
				}
				else{
					m_Cells[i].m_State = 0;
				}
			}
		}
	}
}

//	generators
std::vector <std::vector <std::vector <int> > > Automata::generateSequence(){
	//	check for necessary conditions

}





int main(){

	srand(time(NULL));

	//	initial state
	std::vector<int> initialState;
	for (int i = 0; i < 51; i++){
		initialState.push_back(0);
	}
	initialState[25] = 1;

	Automata test(1, 51, 0, 18, .4, 50);
	test.setCells(initialState);
	//test.printCells();
	test.displayOneDimensionalCells();
	for (int i = 0; i < 25; i++){
		test.updateOneDimensionalCells();
		test.displayOneDimensionalCells();
	}

	return 0;

}