//	Conways game of life, inhereted from Automata

#include "Conway.h"

Conway::Conway(){}
Conway::~Conway(){}

//	Complete constructor
Conway::Conway(int size, int boundary, float density, int times) : m_Dim(2), m_Size(size), m_NumStates(2), m_Boundary(boundary), m_Rule(6152), m_Type(2), m_Density(density), m_Time(times){ srand(time(NULL));}

//	place a CA object at location (x,y) according to the apgcode format
void Conway::placeObject(string apgcode, int x, int y){
	std::vector<std::vector<int> > temp_object = generateObject(apgcode);
}
std::vector<std::vector<int> > Conway::generateObject(string apgcode){
	//	Parse apgcode 
	
}
		
//	Various chipping functions
std::vector<std::vector<std::vector<std::vector<int> > > > Conway::chipSequence(std::vector<std::vector<std::vector<int> > > sequence, int filter_height, int filter_width, int step_x, int step_y){
	std::vector<std::vector<std::vector<std::vector<int> > > > chipped_sequence;
	//	Determine number of steps along x and y
	num_x = floor((sequence[0].size() - filter_height) / step_x);
	num_y = floor((sequence[0][0].size() - filter_width) / step_y);
	for (int i = 0; i < num_x; i++){
		std::vector<std::vector<std::vector<int> > > temp_chip;
		for (int j = 0; j < num_y; j++){
			
		}
	}
	
}
			