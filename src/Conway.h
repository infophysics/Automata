#pragma once

//	Conways game of life, inhereted from Automata

#include "Automata.h"

class Conway : public Automata{
	
	public:
		Conway();
		virtual ~Conway();
		Conway(int size, int boundary, float density, int times);
		
		//	place a CA object at location (x,y) according to the apgcode format
		void placeObject(string apgcode, int x, int y);
		std::vector<std::vector<int> > generateObject(string apgcode);
		
		//	Various chipping functions
		std::vector<std::vector<std::vector<std::vector<int> > > > chipSequence(int filter_height, int filter_width, int step_x, int step_y);
			
	private:
	
	
};