#pragma once

//	Conways game of life, inhereted from Automata

#include "Automata.h"

class Conway : public Automata{
	
	public:
		Conway();
		virtual ~Conway();
		Conway(int size, int boundary, float density, int times);
		
		//	place a CA object at location (x,y) according to the apgcode format
		void placeObject(std::string apgcode, int x, int y);
		std::vector<std::vector<int> > generateObject(std::string apgcode);
		
		//	Various chipping functions
		std::vector<std::vector<std::vector<std::vector<int> > > > chipSequence(std::vector<std::vector<std::vector<int> > > sequence, int filter_width, int filter_height, int step_x, int step_y);
			
	private:
	
	
};