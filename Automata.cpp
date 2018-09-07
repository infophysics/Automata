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
			return m_Cells[0][cell+1] + m_Cells[0][m_Size-1];
		}
		else{
			return m_Cells[0][cell+1];
		}
	}
	else if (cell == m_Size - 1){
		//	check for boundary conditions
		if (m_Boundary == 0){
			return m_Cells[0][cell-1] + m_Cells[0][0];
		}
		else{
			return m_Cells[0][cell-1];
		}
	}
	else{
		return m_Cells[0][cell-1] + m_Cells[0][cell+1];
	}
}

int Automata::findTwoDimensionalState(int cellX, int cellY){
	//	check for boundary cells
	if (cellX == 0){	//	top of grid
		if (cellY == 0){	//	top left
			//	check boundary conditions
			if (m_Boundary == 0){	//	sphere topology
				return m_Cells[0][1] + m_Cells[1][0] + m_Cells[1][1];
			}
			else if (m_Boundary == 1){	//	torus topology
				return m_Cells[0][1] + m_Cells[1][0] + m_Cells[1][1] + m_Cells[0][m_Size-1] + m_Cells[1][m_Size-1] + m_Cells[m_Size-1][0] + m_Cells[m_Size-1][1] + m_Cells[m_Size-1][m_Size-1];
			}
			else if (m_Boundary == 2){	//	cylinder topology
				return m_Cells[0][1] + m_Cells[1][0] + m_Cells[1][1] + m_Cells[0][m_Size-1] + m_Cells[1][m_Size-1];
			}
			else if (m_Boundary == 3){	//	Klein bottle topology
				return m_Cells[0][1] + m_Cells[1][0] + m_Cells[1][1] + m_Cells[0][m_Size-1] + m_Cells[1][m_Size-1] + m_Cells[m_Size-1][0] + m_Cells[m_Size-1][m_Size-2] + m_Cells[m_Size-1][m_Size-1];
			}
			else if (m_Boundary == 4){	//	Mobius strip topology
				return m_Cells[0][1] + m_Cells[1][0] + m_Cells[1][1] + m_Cells[m_Size-2][m_Size-1] + m_Cells[m_Size-1][m_Size-1];
			}
			else{	//	square topology
				return m_Cells[0][1] + m_Cells[1][0] + m_Cells[1][1];
			}
		}
		else if (cellY == m_Size - 1){
			if (m_Boundary == 0){	//	sphere topology
				return m_Cells[0][m_Size-2] + m_Cells[1][m_Size-2] + m_Cells[1][m_Size-1];
			}
			else if (m_Boundary == 1){	//	torus topology
				return m_Cells[0][m_Size-2] + m_Cells[1][m_Size-2] + m_Cells[1][m_Size-1] + m_Cells[0][0] + m_Cells[1][0] + m_Cells[m_Size-1][0] + m_Cells[m_Size-1][m_Size-2] + m_Cells[m_Size-1][m_Size-1];
			}
			else if (m_Boundary == 2){	//	cylinder topology
				return m_Cells[0][m_Size-2] + m_Cells[1][m_Size-2] + m_Cells[1][m_Size-1] + m_Cells[0][0] + m_Cells[1][0];
			}
			else if (m_Boundary == 3){	//	Klein bottle topology
				return m_Cells[0][m_Size-2] + m_Cells[1][m_Size-2] + m_Cells[1][m_Size-1] + m_Cells[0][0] + m_Cells[1][0] + m_Cells[m_Size-1][0] + m_Cells[m_Size-1][1] + m_Cells[m_Size-1][m_Size-1];
			}
			else if (m_Boundary == 4){	//	Mobius strip topology
				return m_Cells[0][m_Size-2] + m_Cells[1][m_Size-2] + m_Cells[1][m_Size-1] + m_Cells[m_Size-2][0] + m_Cells[m_Size-1][0];
			}
			else{	//	square topology
				return m_Cells[0][m_Size-2] + m_Cells[1][m_Size-2] + m_Cells[1][m_Size-1];
			}
		}
		else{
			if (m_Boundary == 0){	//	sphere topology
				return m_Cells[0][cellY-1] + m_Cells[0][cellY+1] + m_Cells[1][cellY-1] + m_Cells[1][cellY] + m_Cells[1][cellY+1];
			}
			else if (m_Boundary == 1){	//	torus topology
				return m_Cells[0][cellY-1] + m_Cells[0][cellY+1] + m_Cells[1][cellY-1] + m_Cells[1][cellY] + m_Cells[1][cellY+1] + m_Cells[m_Size-1][cellY-1] + m_Cells[m_Size-1][cellY] + m_Cells[m_Size-1][cellY+1];
			}
			else if (m_Boundary == 2){	//	cylinder topology
				return m_Cells[0][cellY-1] + m_Cells[0][cellY+1] + m_Cells[1][cellY-1] + m_Cells[1][cellY] + m_Cells[1][cellY+1];
			}
			else if (m_Boundary == 3){	//	Klein bottle topology
				return m_Cells[0][cellY-1] + m_Cells[0][cellY+1] + m_Cells[1][cellY-1] + m_Cells[1][cellY] + m_Cells[1][cellY+1] + m_Cells[m_Size-1][m_Size-cellY-1] + m_Cells[m_Size-1][m_Size-cellY] + m_Cells[m_Size-1][m_Size-cellY+1];
			}
			else if (m_Boundary == 4){	//	Mobius strip topology
				return m_Cells[0][cellY-1] + m_Cells[0][cellY+1] + m_Cells[1][cellY-1] + m_Cells[1][cellY] + m_Cells[1][cellY+1];
			}
			else{	//	square topology
				return m_Cells[0][cellY-1] + m_Cells[0][cellY+1] + m_Cells[1][cellY-1] + m_Cells[1][cellY] + m_Cells[1][cellY+1];
			}
		}
	}
	else if (cellX == m_Size-1){
		if (cellY == 0){	//	top left
			//	check boundary conditions
			if (m_Boundary == 0){	//	sphere topology
				return m_Cells[m_Size-1][1] + m_Cells[m_Size-2][0] + m_Cells[m_Size-2][1];
			}
			else if (m_Boundary == 1){	//	torus topology
				return m_Cells[m_Size-1][1] + m_Cells[m_Size-2][0] + m_Cells[m_Size-2][1] + m_Cells[m_Size-1][m_Size-1] + m_Cells[m_Size-2][m_Size-1] + m_Cells[0][0] + m_Cells[0][1] + m_Cells[0][m_Size-1];
			}
			else if (m_Boundary == 2){	//	cylinder topology
				return m_Cells[m_Size-1][1] + m_Cells[m_Size-2][0] + m_Cells[m_Size-2][1] + m_Cells[m_Size-1][m_Size-1] + m_Cells[m_Size-2][m_Size-1];
			}
			else if (m_Boundary == 3){	//	Klein bottle topology
				return m_Cells[m_Size-1][1] + m_Cells[m_Size-2][0] + m_Cells[m_Size-2][1] + m_Cells[m_Size-1][m_Size-1] + m_Cells[m_Size-2][m_Size-1] + m_Cells[0][0] + m_Cells[0][m_Size-2] + m_Cells[0][m_Size-1];
			}
			else if (m_Boundary == 4){	//	Mobius strip topology
				return m_Cells[m_Size-1][1] + m_Cells[m_Size-2][0] + m_Cells[m_Size-2][1] + m_Cells[1][m_Size-1] + m_Cells[0][m_Size-1];
			}
			else{	//	square topology
				return m_Cells[m_Size-1][1] + m_Cells[m_Size-2][0] + m_Cells[m_Size-2][1];
			}
		}
		else if (cellY == m_Size - 1){
			if (m_Boundary == 0){	//	sphere topology
				return m_Cells[m_Size-1][m_Size-2] + m_Cells[m_Size-2][m_Size-2] + m_Cells[m_Size-2][m_Size-1];
			}
			else if (m_Boundary == 1){	//	torus topology
				return m_Cells[m_Size-1][m_Size-2] + m_Cells[m_Size-2][m_Size-2] + m_Cells[m_Size-2][m_Size-1] + m_Cells[m_Size-1][0] + m_Cells[m_Size-2][0] + m_Cells[0][0] + m_Cells[0][m_Size-2] + m_Cells[0][m_Size-1];
			}
			else if (m_Boundary == 2){	//	cylinder topology
				return m_Cells[m_Size-1][m_Size-2] + m_Cells[m_Size-2][m_Size-2] + m_Cells[m_Size-2][m_Size-1] + m_Cells[m_Size-1][0] + m_Cells[m_Size-2][0];
			}
			else if (m_Boundary == 3){	//	Klein bottle topology
				return m_Cells[m_Size-1][m_Size-2] + m_Cells[m_Size-2][m_Size-2] + m_Cells[m_Size-2][m_Size-1] + m_Cells[m_Size-1][0] + m_Cells[m_Size-2][0] + m_Cells[0][0] + m_Cells[0][1] + m_Cells[0][m_Size-1];
			}
			else if (m_Boundary == 4){	//	Mobius strip topology
				return m_Cells[m_Size-1][m_Size-2] + m_Cells[m_Size-2][m_Size-2] + m_Cells[m_Size-2][m_Size-1] + m_Cells[1][0] + m_Cells[0][0];
			}
			else{	//	square topology
				return m_Cells[m_Size-1][m_Size-2] + m_Cells[m_Size-2][m_Size-2] + m_Cells[m_Size-2][m_Size-1];
			}
		}
		else{
			if (m_Boundary == 0){	//	sphere topology
				return m_Cells[m_Size-1][cellY-1] + m_Cells[m_Size-1][cellY+1] + m_Cells[m_Size-2][cellY-1] + m_Cells[m_Size-2][cellY] + m_Cells[m_Size-2][cellY+1];
			}
			else if (m_Boundary == 1){	//	torus topology
				return m_Cells[m_Size-1][cellY-1] + m_Cells[m_Size-1][cellY+1] + m_Cells[m_Size-2][cellY-1] + m_Cells[m_Size-2][cellY] + m_Cells[m_Size-2][cellY+1] + m_Cells[0][cellY-1] + m_Cells[0][cellY] + m_Cells[0][cellY+1];
			}
			else if (m_Boundary == 2){	//	cylinder topology
				return m_Cells[m_Size-1][cellY-1] + m_Cells[m_Size-1][cellY+1] + m_Cells[m_Size-2][cellY-1] + m_Cells[m_Size-2][cellY] + m_Cells[m_Size-2][cellY+1];
			}
			else if (m_Boundary == 3){	//	Klein bottle topology
				return m_Cells[m_Size-1][cellY-1] + m_Cells[m_Size-1][cellY+1] + m_Cells[m_Size-2][cellY-1] + m_Cells[m_Size-2][cellY] + m_Cells[m_Size-2][cellY+1] + m_Cells[0][m_Size-cellY-1] + m_Cells[0][m_Size-cellY] + m_Cells[0][m_Size-cellY+1];
			}
			else if (m_Boundary == 4){	//	Mobius strip topology
				return m_Cells[m_Size-1][cellY-1] + m_Cells[m_Size-1][cellY+1] + m_Cells[m_Size-2][cellY-1] + m_Cells[m_Size-2][cellY] + m_Cells[m_Size-2][cellY+1];
			}
			else{	//	square topology
				return m_Cells[m_Size-1][cellY-1] + m_Cells[m_Size-1][cellY+1] + m_Cells[m_Size-2][cellY-1] + m_Cells[m_Size-2][cellY] + m_Cells[m_Size-2][cellY+1];
			}
		}
	}
	else{	//sides
		if (cellY == 0){	//	top left
			//	check boundary conditions
			if (m_Boundary == 0){	//	sphere topology
				return m_Cells[cellX][1] + m_Cells[cellX-1][0] + m_Cells[cellX-1][1] + m_Cells[cellX+1][0] + m_Cells[cellX+1][1];
			}
			else if (m_Boundary == 1){	//	torus topology
				return m_Cells[cellX][1] + m_Cells[cellX-1][0] + m_Cells[cellX-1][1] + m_Cells[cellX+1][0] + m_Cells[cellX+1][1] + m_Cells[cellX-1][m_Size-1] + m_Cells[cellX+1][m_Size-1] + m_Cells[cellX][m_Size-1];
			}
			else if (m_Boundary == 2){	//	cylinder topology
				return m_Cells[cellX][1] + m_Cells[cellX-1][0] + m_Cells[cellX-1][1] + m_Cells[cellX+1][0] + m_Cells[cellX+1][1] + m_Cells[cellX-1][m_Size-1] + m_Cells[cellX+1][m_Size-1] + m_Cells[cellX][m_Size-1];
			}
			else if (m_Boundary == 3){	//	Klein bottle topology
				return m_Cells[cellX][1] + m_Cells[cellX-1][0] + m_Cells[cellX-1][1] + m_Cells[cellX+1][0] + m_Cells[cellX+1][1] + m_Cells[cellX-1][m_Size-1] + m_Cells[cellX+1][m_Size-1] + m_Cells[cellX][m_Size-1];
			}
			else if (m_Boundary == 4){	//	Mobius strip topology
				return m_Cells[cellX][1] + m_Cells[cellX-1][0] + m_Cells[cellX-1][1] + m_Cells[cellX+1][0] + m_Cells[cellX+1][1] + m_Cells[m_Size-cellX-1][m_Size-1] + m_Cells[m_Size-cellX+1][m_Size-1] + m_Cells[m_Size-cellX][m_Size-1];
			}
			else{	//	square topology
				return m_Cells[cellX][1] + m_Cells[cellX-1][0] + m_Cells[cellX-1][1] + m_Cells[cellX+1][0] + m_Cells[cellX+1][1];
			}
		}
		else if (cellY == m_Size - 1){
			if (m_Boundary == 0){	//	sphere topology
				return m_Cells[cellX][m_Size-2] + m_Cells[cellX-1][m_Size-1] + m_Cells[cellX-1][m_Size-2] + m_Cells[cellX+1][m_Size-1] + m_Cells[cellX+1][m_Size-2];
			}
			else if (m_Boundary == 1){	//	torus topology
				return m_Cells[cellX][m_Size-2] + m_Cells[cellX-1][m_Size-1] + m_Cells[cellX-1][m_Size-2] + m_Cells[cellX+1][m_Size-1] + m_Cells[cellX+1][m_Size-2] + m_Cells[cellX-1][0] + m_Cells[cellX][0] + m_Cells[cellX+1][0];
			}
			else if (m_Boundary == 2){	//	cylinder topology
				return m_Cells[cellX][m_Size-2] + m_Cells[cellX-1][m_Size-1] + m_Cells[cellX-1][m_Size-2] + m_Cells[cellX+1][m_Size-1] + m_Cells[cellX+1][m_Size-2] + m_Cells[cellX-1][0] + m_Cells[cellX][0] + m_Cells[cellX+1][0];
			}
			else if (m_Boundary == 3){	//	Klein bottle topology
				return m_Cells[cellX][m_Size-2] + m_Cells[cellX-1][m_Size-1] + m_Cells[cellX-1][m_Size-2] + m_Cells[cellX+1][m_Size-1] + m_Cells[cellX+1][m_Size-2] + m_Cells[cellX-1][0] + m_Cells[cellX][0] + m_Cells[cellX+1][0];
			}
			else if (m_Boundary == 4){	//	Mobius strip topology
				return m_Cells[cellX][m_Size-2] + m_Cells[cellX-1][m_Size-1] + m_Cells[cellX-1][m_Size-2] + m_Cells[cellX+1][m_Size-1] + m_Cells[cellX+1][m_Size-2] + m_Cells[m_Size-cellX-1][0] + m_Cells[m_Size-cellX][0] + m_Cells[m_Size-cellX+1][0];
			}
			else{	//	square topology
				return m_Cells[cellX][m_Size-2] + m_Cells[cellX-1][m_Size-1] + m_Cells[cellX-1][m_Size-2] + m_Cells[cellX+1][m_Size-1] + m_Cells[cellX+1][m_Size-2];
			}
		}
		else{
			return m_Cells[cellX][cellY+1] + m_Cells[cellX][cellY-1] + m_Cells[cellX+1][cellY-1] + m_Cells[cellX+1][cellY] + m_Cells[cellX+1][cellY+1] + m_Cells[cellX-1][cellY-1] + m_Cells[cellX-1][cellY] + m_Cells[cellX-1][cellY+1];
		}
	}
}

//	updating cells
void Automata::updateOneDimensionalCells(){

}
void Automata::updateTwoDimensionalCells(){

}

//	printing
void Automata::printCells(){
	for (int i = 0; i < m_Cells.size(); i++){
		for (int j = 0; j < m_Cells[0].size(); j++){
			std::cout << m_Cells[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Automata::displayOneDimensionalCells(){
	for (int i = 0; i < 100; i++){
			std::cout << std::endl;
		}
		std::cout << "|";
		for (int j = 0; j < m_Size; j++){
			if (m_Cells[0][j] == 0){
				std::cout << " ";
			}
			else{
				std::cout << "o";
			}
		}
		std::cout << "|" << std::endl;
}


void Automata::displayTwoDimensionalCells(){
	for (int i = 0; i < 100; i++){
		std::cout << std::endl;
	}
	for (int i = 0; i < m_Size; i++){
		std::cout << "|";
		for (int j = 0; j < m_Size; j++){
			if (m_Cells[i][j] == 0){
				std::cout << " ";
			}
			else{
				std::cout << "o";
			}
		}
		std::cout << "|" << std::endl;
	}
}

//	initializers
void Automata::initializeEmptyCells(){
	if (m_Type == 1){
		std::vector <int> tempCells;
		for (int i = 0; i < m_Size; i++){
			tempCells.push_back(0);
		}
		m_Cells.push_back(tempCells);
	}
	else if (m_Type == 2){
		for (int j = 0; j < m_Size; j++){
			std::vector <int> tempCells;
			for (int i = 0; i < m_Size; i++){
				tempCells.push_back(0);
			}
			m_Cells.push_back(tempCells);
		}
	}
}

void Automata::initializeCells(){
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
					m_Cells[0][i] = 1;
				}
				else{
					m_Cells[0][i] = 0;
				}
			}
		}
		else{
			for (int j = 0; j < m_Size; j++){
				for (int i = 0; i < m_Size; i++){
					if ((float)rand()/RAND_MAX <= m_Density){
						m_Cells[j][i] = 1;
					}
					else{
						m_Cells[j][i] = 0;
					}
				}
			}
		}
	}
}
//	initializer with density
void Automata::initializeCells(float density){
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
					m_Cells[0][i] = 1;
				}
				else{
					m_Cells[0][i] = 0;
				}
			}
		}
		else{
			for (int j = 0; j < m_Size; j++){
				for (int i = 0; i < m_Size; i++){
					if ((float)rand()/RAND_MAX <= density){
						m_Cells[j][i] = 1;
					}
					else{
						m_Cells[j][i] = 0;
					}
				}
			}
		}
	}
}

//	generators
std::vector <std::vector <std::vector <int> > > Automata::generateSequence(){
	//	check for necessary conditions

}


//	rules
void Automata::oneDimensionRule1(){

}
void Automata::oneDimensionRule2(){

}
void Automata::oneDimensionRule3(){

}
void Automata::oneDimensionRule4(){

}
void Automata::oneDimensionRule5(){

}
void Automata::oneDimensionRule6(){

}
void Automata::oneDimensionRule7(){

}
void Automata::oneDimensionRule8(){

}


int main(){

	srand(time(NULL));

	Automata test(1, 50, 0, 1, .4, 50);
	test.printCells();
	test.displayOneDimensionalCells();
	return 0;

}
