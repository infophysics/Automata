/*
 * Automata.h
 *
 *  Created on: Sep 5, 2018
 *      Author: ncarrara
 */

#ifndef AUTOMATA_H_
#define AUTOMATA_H_

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <random>
#include <time.h>
#include <cstdlib>



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
		//	getters
		int getBoundary(){return m_Boundary;}
		int getRule(){return m_Rule;}
		float getDensity(){return m_Density;}
		int getTime(){return m_Time;}

		//	state determination
		int findOneDimensionalState(int cell);
		int findTwoDimensionalState(int cellX, int cellY);

		//	updating cells
		void updateOneDimensionalCells();
		void updateTwoDimensionalCells();

		//	printing
		void printCells();
		void displayOneDimensionalCells();
		void displayTwoDimensionalCells();

		//	initializers
		void initializeEmptyCells();
		void initializeCells();
		void initializeCells(float density);

		//	generators
		std::vector <std::vector <std::vector <int> > > generateSequence();
		std::vector <std::vector <std::vector <int> > > generateSequence(int time);

		//	rules
		void oneDimensionRule1();
		void oneDimensionRule2();
		void oneDimensionRule3();
		void oneDimensionRule4();
		void oneDimensionRule5();
		void oneDimensionRule6();
		void oneDimensionRule7();
		void oneDimensionRule8();


	private:
		std::vector <std::vector<int> > m_Cells;	//	array of cells
		int m_Type;								//	either 1 for 1d or 2 for 2d
		int m_Size;								//	size of cells
		int m_Boundary;							//	boundary conditions 1d-(0-circle, 1-line), 2d-(0-sphere,1-torus,2-cylinder,3-klein_bottle,4-mobius,5-square)
		int m_Rule;								//	automata rule, 1d-2^2 = 4, 2d-2^9 = 512
		float m_Density;						//	initial density, 0.-1.
		int m_Time;								//	number of time steps




};

#endif /* AUTOMATA_H_ */
