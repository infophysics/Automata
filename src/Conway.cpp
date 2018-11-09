//	Conways game of life, inhereted from Automata

#include "Conway.h"

Conway::Conway(){}
Conway::~Conway(){}

//	Complete constructor
Conway::Conway(int size, int boundary, float density, int times){
	setDim(2);
	setSize(size);
	setBoundary(boundary);
	setNumStates(2);
	setType(2);
	setDensity(density);
	setRule(6152);
	setTime(times);
	srand(time(NULL));
}

//	place a CA object at location (x,y) according to the apgcode format
//void Conway::placeObject(string apgcode, int x, int y){
///	std::vector<std::vector<int> > temp_object = generateObject(apgcode);
//}
//std::vector<std::vector<int> > Conway::generateObject(string apgcode){
	//	Parse apgcode 
	
//}
		
//	Various chipping functions
std::vector<std::vector<std::vector<std::vector<int> > > > Conway::chipSequence(std::vector<std::vector<std::vector<int> > > sequence, int filter_width, int filter_height, int step_x, int step_y){
	std::vector<std::vector<std::vector<std::vector<int> > > > chipped_sequence;
	//	Determine number of steps along x and y
	int num_x = floor((sequence[0].size() - filter_width) / step_x);
	int num_y = floor((sequence[0][0].size() - filter_height) / step_y);
	for (int i = 0; i < num_x; i++){
		for (int j = 0; j < num_y; j++){
			std::vector<std::vector<std::vector<int> > > temp_chip;
			//	iterate over each time step
			std::vector<std::vector<int> > temp_sequence;
			for (int k = 0; k < sequence.size(); k++){
				//	iterate over each row
				for (int xx = (i*step_x); xx < (i*step_x + filter_width); xx++){
					std::vector<int> temp_row;
					for(int yy = (j*step_y); yy < (j*step_y + filter_height); yy++){
						temp_row.push_back(sequence[k][xx][yy]);
					}
					temp_sequence.push_back(temp_row);
				}
				temp_chip.push_back(temp_sequence);
			}
			chipped_sequence.push_back(temp_chip);
		}	
	}
	return chipped_sequence;
}
			