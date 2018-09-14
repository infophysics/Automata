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

//	Cell struct
struct Cell{
	int m_State;	//	self state
	std::vector<int> m_NState{0,0,0,0,0,0,0,0};	//	neighbors state 0-8 for 1d using the Wolfram rules
	Cell(int state) : m_State(state) {}
};


class Automata {


	public:
		Automata();
		virtual ~Automata();
		Automata(int type);
		Automata(int type, int size);
		Automata(int type, int size, int boundary);
		Automata(int type, int size, int boundary, int rule);
		Automata(int type, int size, int boundary, int rule, float density);
		Automata(int type, int size, int boundary, int rule, float density, int time);
		//	setters
		void setBoundary(int boundary){m_Boundary = boundary;}
		void setRule(int rule){m_Rule = rule;}
		void setDensity(float density){m_Density = density;}
		void setTime(int time){m_Time = time;}
		//	set cell values
		void setCells(std::vector<std::vector<int> > states);
		//	getters
		int getBoundary(){return m_Boundary;}
		int getRule(){return m_Rule;}
		float getDensity(){return m_Density;}
		int getTime(){return m_Time;}

		//	state determination (class 1)
		int findOneDimensionalState(int cell);
		int findTwoDimensionalvonNeumannState(int cellX, int cellY);
		//int findTwoDimensionalMooreState(int cellX, int cellY);	//	not happening
		
		//	state determination (class 2)
		int findOneDimensionalState2(int cell);
		int findTwoDimensionalvonNeummanState2(int cellX, int cellY);
		int findTwoDimensionalMooreState2(int cellX, int cellY);
		
		//	updating cells
		void findOneDimensionalUpdateRule();
		void findTwoDimensionalvonNeumannUpdateRule();
		void findTwoDimensionalvonNeumannUpdateRule2();
		void findTwoDimensionalMooreUpdateRule2();
		void updateOneDimensionalCells();
		void updateTwoDimensionalvonNeumannCells();

		//	printing
		void printCells();
		void displayOneDimensionalCells();
		void displayTwoDimensionalCells();

		//	initializers
		void initializeOneDimensionalEmptyCells();
		void initializeOneDimensionalCells();
		void initializeTwoDimensionalEmptyCells();
		void initializeTwoDimensionalCells();
		//void initializeCells(float density);

		//	generators
		std::vector <std::vector <int> > generateOneDimensionalSequence();
		//std::vector <std::vector <int> > generateSequence(int time);

		//	save sequence to file
		void saveSequenceToFile(std::vector <std::vector <int> > sequence, const char * fileName);


	private:
		std::vector <std::vector < Cell > > m_Cells;	//	array of cells
		std::vector < int > m_UpdateRule;//	update rule
		int m_Type;						//	either 1 for 1d or 2 for 2d
		int m_Size;						//	size of cells
		int m_Boundary;					//	boundary conditions 1d-(0-circle, 1-line), 2d-(0-sphere,1-torus,2-cylinder,3-klein_bottle,4-mobius,5-square)
		int m_Rule;						//	automata rule, 1d-2^2 = 4, 2d-2^9 = 512
		float m_Density;				//	initial density, 0.-1.
		int m_Time;						//	number of time steps




};


