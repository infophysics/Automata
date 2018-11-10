/*
 * Automata.h
 *
 *  Created on: Sep 5, 2018
 *      Author: ncarrara
 */

#pragma once

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <random>
#include <time.h>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iterator>

//	Cell struct
struct Cell{
	int m_State;	//	self state
	int m_NumStates;
	std::vector<int> m_NState;	//	neighbors state using the Wolfram rules
	Cell(int state, int numStates) : m_State(state), m_NumStates(numStates) {
		for(int i = 0; i < numStates; i++){
			m_NState.push_back(0);
		}
	}
};


class Automata {


	public:
		Automata();
		virtual ~Automata();
		Automata(int dim, int size, int numStates);
		Automata(int dim, int size, int numStates, int boundary);
		Automata(int dim, int size, int numStates, int boundary, int rule);
		Automata(int dim, int size, int numStates, int boundary, int rule, int type);
		Automata(int dim, int size, int numStates, int boundary, int rule, int type, float density);
		Automata(int dim, int size, int numStates, int boundary, int rule, int type, float density, int times);
		//	setters
		void setDim(int dim){m_Dim = dim;}
		void setSize(int size){m_Size = size;}
		void setNumStates(int numStates){m_NumStates = numStates;}
		void setBoundary(int boundary){m_Boundary = boundary;}
		void setRule(int rule){m_Rule = rule;}
		void setType(int type){m_Type = type;}
		void setDensity(float density){m_Density = density;}
		void setTime(int time){m_Time = time;}
		//	set cell values
		void setCells(std::vector<std::vector<int> > states);
		void setCells(std::vector<std::vector<Cell> > cells){m_Cells = cells;}
		//	getters
		int getBoundary(){return m_Boundary;}
		int getRule(){return m_Rule;}
		float getDensity(){return m_Density;}
		int getTime(){return m_Time;}
		int getSize(){return m_Size;}
		std::vector <std::vector < Cell > > getCells(){return m_Cells;}

		//	states
		int findOneDimensionalState(int cell);
		//	state determination (type 1)
		int findOneDimensionalState_2State(int cell);
		//	state determination (type 2)
		int findOneDimensionalState_2State2(int cell);
		int findOneDimensionalState_3State2(int cell);
		
		//	two dimensional states
		int findTwoDimensionalState(int cellX, int cellY);
		//	state determination (type 1)
		int findTwoDimensionalvonNeumannState_2State(int cellX, int cellY);
		//int findTwoDimensionalMooreState(int cellX, int cellY);	//	not happening
		//	state determination (type 2)
		int findTwoDimensionalvonNeumannState_2State2(int cellX, int cellY);
		int findTwoDimensionalMooreState_2State2(int cellX, int cellY);
		int findTwoDimensionalMooreState_NState2(int cellX, int cellY);
		
		//	updating cells
		void findOneDimensionalUpdateRule();
		void findOneDimensionalUpdateRule_2State();
		void findOneDimensionalUpdateRule_3State2();
		
		void findTwoDimensionalUpdateRule();
		void findTwoDimensionalvonNeumannUpdateRule_2State();
		void findTwoDimensionalvonNeumannUpdateRule_2State2();
		void findTwoDimensionalMooreUpdateRule_2State2();
		void findTwoDimensionalMooreUpdateRule_NState2(std::string rule);
		
		void updateOneDimensionalCells();
		void updateOneDimensionalCells_2State();
		void updateOneDimensionalCells_3State2();
		
		void updateTwoDimensionalCells();
		void updateTwoDimensionalvonNeumannCells_2State();
		void updateTwoDimensionalvonNeumannCells_2State2();
		void updateTwoDimensionalMooreCells_2State2();
		void updateTwoDimensionalMooreCells_NState2();

		//	printing
		void printCells();
		void displayOneDimensionalCells_2State();
		void displayOneDimensionalCells_3State();
		void displayTwoDimensionalCells_2State();

		//	initializers
		void initializeOneDimensionalEmptyCells();
		void initializeOneDimensionalCells();
		void initializeTwoDimensionalEmptyCells();
		void initializeTwoDimensionalCells();
		//void initializeCells(float density);

		//	generators
		std::vector <std::vector <int> > generateOneDimensionalSequence();
		std::vector <std::vector <int> > generateOneDimensionalSequence_2State();
		std::vector <std::vector <int> > generateOneDimensionalSequence_3State2();
		//std::vector <std::vector <int> > generateSequence(int time);
		
		std::vector<std::vector <std::vector <int>  > > generateTwoDimensionalSequence();
		std::vector<std::vector <std::vector <int>  > > generateTwoDimensionalSequence_2State();
		//	save sequence to file
		void saveOneDimensionalSequenceToFile(std::vector <std::vector <int> > sequence, const char * fileName);
		void saveTwoDimensionalSequenceToFile(std::vector <std::vector <std::vector <int> > > sequence, const char * fileName);


	private:
		std::vector <std::vector < Cell > > m_Cells;	//	array of cells
		std::vector < int > m_UpdateRule;//	update rule
		int m_NumStates;				//	number of states for each cell
		int m_Dim;						//	either 1 for 1d or 2 for 2d
		int m_Type;						//	either 0 for unique states, or 1 for equivalence classes of states (totality).
		int m_Order;					//	NN order, 1st order, 2nd order only
		int m_Size;						//	size of cells
		int m_Boundary;					//	boundary conditions 1d-(0-circle, 1-line), 2d-(0-sphere,1-torus,2-cylinder,3-klein_bottle,4-mobius,5-square)
		int m_Rule;						//	automata rule, 1d-2^2 = 4, 2d-2^9 = 512
		float m_Density;				//	initial density, 0.-1.
		int m_Time;						//	number of time steps




};


