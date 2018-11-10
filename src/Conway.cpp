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

Conway::Conway(std::string rulestring, int size, int boundary, float density, int times){
	setDim(2);
	setSize(size);
	setBoundary(boundary);
	setType(2);
	setDensity(density);
	setTime(times);
	srand(time(NULL));
	findTwoDimensionalMooreUpdateRule_NState2(rulestring);
}

//	place a CA object at location (x,y) according to the apgcode format
void Conway::placeObject(std::string apgcode, int x, int y, bool opaque){
	std::vector <std::vector < Cell > > temp_Cells = getCells();
	std::vector<std::vector<int> > temp_object = generateObject(apgcode);
	int height = temp_object.size();
	int width = temp_object[0].size();
	if (getSize() < x + width || getSize() < y + height){
		std::cout << "ERROR! Object of size " << height << "x" << width << " will not fit in grid!" << std::endl;
		return;
	}
	else{
		for (int i = 0; i < height; i++){
			for (int j = 0; j < width; j++){
				if (!opaque){
					temp_Cells[i+x][j+y].m_State = temp_object[i][j];
				}
				else{
					if (temp_object[i][j] == 1){
						temp_Cells[i+x][j+y].m_State = 1;
					}
				}
			}
		}
	}
	setCells(temp_Cells);
}

std::vector<std::vector<int> > Conway::generateObject(std::string apgcode){
	//	Parse apgcode 
	std::vector<std::vector<int> > temp_object;
	//	Find the maximum number of columns
	//std::istringstream iss(apgcode);
	//std::vector<std::string> results((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());
	//std::cout << results[0] << std::endl;
	//	separate contiguous rows of 5
	std::vector<std::string> results;
	for (int i = 0; i < apgcode.size(); i++){
		std::stringstream ss;
		std::string s;
		ss << apgcode[i];
		ss >> s;
		results.push_back(s);
	}
	std::vector<std::vector<std::string> > cont_rows;
	int type = 0;	//	either xs for still life, xp for oscillator, sq for spaceship, methuselah for methuselah.
	std::string digits;	//	either period for oscillator, population for still life, etc.
	int dig;
	int begin;
	if (results[0] == "x"){
		if (results[1] == "s"){
			type = 0;
		}
		else if (results[1] == "p"){
			type = 1;
		}
		else if (results[1] == "q"){
			type = 2;
		}
		for (int i = 2; i < results.size(); i++){
			if (results[i] == "_"){
				begin = i+1;
				break;
			}
			else{
				digits += results[i];
			}
		}
		dig = std::atoi(digits.c_str());
	}
	else if (results[0] == "m" && results[1] == "e" && results[2] == "t" && results[3] == "h" && results[4] == "u" && results[5] == "s" && results[6] == "e" && results[7] == "l" && results[8] == "a" && results[9] == "h"){
		type = 3;
		for (int i = 10; i < results.size(); i++){
			if (results[i] == "_"){
				begin = i+1;
				break;
			}
			else{
				digits += results[i];
			}
		}
		dig = std::atoi(digits.c_str());
	}
	int num_z = 0;
	//	Now parse each five row set
	int num_rows = 1;
	for (int i = begin; i < results.size(); i++){
		if (results[i] == "z"){
			num_z++;
			num_rows++;
			while(results[i+1] == "z"){
				num_z++;
				num_rows++;
				i++;
			}
		}
	}
	int iter = begin;
	for (int j = 0; j < num_rows; j++){
		std::vector<std::string> temp_row;
		for (int i = iter; i < results.size(); i++){
			if (results[i] != "z"){
				temp_row.push_back(results[i]);
			}
			else{
				if (temp_row.size() == 0) temp_row.push_back("z");
				iter = i+1;
				break;
			}
		}
		cont_rows.push_back(temp_row);
	}
	int max = 0;
	for (int j = 0; j < num_rows; j++){
		int temp_max = 0;
		if (cont_rows[j].size() == 0) break;
		for (int k = 0; k < cont_rows[j].size(); k++){
			if (cont_rows[j][k] == "w") temp_max += 2;
			else if (cont_rows[j][k] == "x") temp_max += 3;
			else if (cont_rows[j][k] == "y"){
				if (cont_rows[j][k+1] == "0") temp_max += 4;
				else if (cont_rows[j][k+1] == "1") temp_max += 5;
				else if (cont_rows[j][k+1] == "2") temp_max += 6;
				else if (cont_rows[j][k+1] == "3") temp_max += 7;
				else if (cont_rows[j][k+1] == "4") temp_max += 8;
				else if (cont_rows[j][k+1] == "5") temp_max += 9;
				else if (cont_rows[j][k+1] == "6") temp_max += 10;
				else if (cont_rows[j][k+1] == "7") temp_max += 11;
				else if (cont_rows[j][k+1] == "8") temp_max += 12;
				else if (cont_rows[j][k+1] == "9") temp_max += 13;
				else if (cont_rows[j][k+1] == "a") temp_max += 14;
				else if (cont_rows[j][k+1] == "b") temp_max += 15;
				else if (cont_rows[j][k+1] == "c") temp_max += 16;
				else if (cont_rows[j][k+1] == "d") temp_max += 17;
				else if (cont_rows[j][k+1] == "e") temp_max += 18;
				else if (cont_rows[j][k+1] == "f") temp_max += 19;
				else if (cont_rows[j][k+1] == "g") temp_max += 20;
				else if (cont_rows[j][k+1] == "h") temp_max += 21;
				else if (cont_rows[j][k+1] == "i") temp_max += 22;
				else if (cont_rows[j][k+1] == "j") temp_max += 23;
				else if (cont_rows[j][k+1] == "k") temp_max += 24;
				else if (cont_rows[j][k+1] == "l") temp_max += 25;
				else if (cont_rows[j][k+1] == "m") temp_max += 26;
				else if (cont_rows[j][k+1] == "n") temp_max += 27;
				else if (cont_rows[j][k+1] == "o") temp_max += 28;
				else if (cont_rows[j][k+1] == "p") temp_max += 29;
				else if (cont_rows[j][k+1] == "q") temp_max += 30;
				else if (cont_rows[j][k+1] == "r") temp_max += 31;
				else if (cont_rows[j][k+1] == "s") temp_max += 32;
				else if (cont_rows[j][k+1] == "t") temp_max += 33;
				else if (cont_rows[j][k+1] == "u") temp_max += 34;
				else if (cont_rows[j][k+1] == "v") temp_max += 35;
				else if (cont_rows[j][k+1] == "w") temp_max += 36;
				else if (cont_rows[j][k+1] == "x") temp_max += 37;
				else if (cont_rows[j][k+1] == "y") temp_max += 38;
				else if (cont_rows[j][k+1] == "z") temp_max += 39;
				k++;
			}
			else temp_max += 1;
		}
		if (temp_max > max) max = temp_max;
	}
	int num_x = 5 + num_z*5;
	int num_y = max;
	for (int i = 0; i < num_x; i++){
		std::vector<int> temp_row;
		for (int j = 0; j < num_y; j++){
			temp_row.push_back(0);
		}
		temp_object.push_back(temp_row);
	}
	//	populate the temp_object
	for (int j = 0; j < num_rows; j++){
			int count = 0;
			if (cont_rows[j].size() == 0) break;
			for (int k = 0; k < cont_rows[j].size(); k++){
				if (cont_rows[j][k] == "0"){count+=1;}
				if (cont_rows[j][k] == "w"){count+=2;}
				else if (cont_rows[j][k] == "x"){count+=3;}
				else if (cont_rows[j][k] == "y"){
					if (cont_rows[j][k+1] == "0") count += 4;
					else if (cont_rows[j][k+1] == "1") count += 5;
					else if (cont_rows[j][k+1] == "2") count += 6;
					else if (cont_rows[j][k+1] == "3") count += 7;
					else if (cont_rows[j][k+1] == "4") count += 8;
					else if (cont_rows[j][k+1] == "5") count += 9;
					else if (cont_rows[j][k+1] == "6") count += 10;
					else if (cont_rows[j][k+1] == "7") count += 11;
					else if (cont_rows[j][k+1] == "8") count += 12;
					else if (cont_rows[j][k+1] == "9") count += 13;
					else if (cont_rows[j][k+1] == "a") count += 14;
					else if (cont_rows[j][k+1] == "b") count += 15;
					else if (cont_rows[j][k+1] == "c") count += 16;
					else if (cont_rows[j][k+1] == "d") count += 17;
					else if (cont_rows[j][k+1] == "e") count += 18;
					else if (cont_rows[j][k+1] == "f") count += 19;
					else if (cont_rows[j][k+1] == "g") count += 20;
					else if (cont_rows[j][k+1] == "h") count += 21;
					else if (cont_rows[j][k+1] == "i") count += 22;
					else if (cont_rows[j][k+1] == "j") count += 23;
					else if (cont_rows[j][k+1] == "k") count += 24;
					else if (cont_rows[j][k+1] == "l") count += 25;
					else if (cont_rows[j][k+1] == "m") count += 26;
					else if (cont_rows[j][k+1] == "n") count += 27;
					else if (cont_rows[j][k+1] == "o") count += 28;
					else if (cont_rows[j][k+1] == "p") count += 29;
					else if (cont_rows[j][k+1] == "q") count += 30;
					else if (cont_rows[j][k+1] == "r") count += 31;
					else if (cont_rows[j][k+1] == "s") count += 32;
					else if (cont_rows[j][k+1] == "t") count += 33;
					else if (cont_rows[j][k+1] == "u") count += 34;
					else if (cont_rows[j][k+1] == "v") count += 35;
					else if (cont_rows[j][k+1] == "w") count += 36;
					else if (cont_rows[j][k+1] == "x") count += 37;
					else if (cont_rows[j][k+1] == "y") count += 38;
					else if (cont_rows[j][k+1] == "z") count += 39;
					k++;
				}
				else if (cont_rows[j][k] == "z") break;
				else if (cont_rows[j][k] == "1"){
					temp_object[j*5][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "2"){
					temp_object[j*5+1][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "3"){
					temp_object[j*5][count] = 1;
					temp_object[j*5+1][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "4"){
					temp_object[j*5+2][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "5"){
					temp_object[j*5][count] = 1;
					temp_object[j*5+2][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "6"){
					temp_object[j*5+1][count] = 1;
					temp_object[j*5+2][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "7"){
					temp_object[j*5][count] = 1;
					temp_object[j*5+1][count] = 1;
					temp_object[j*5+2][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "8"){
					temp_object[j*5+3][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "9"){
					temp_object[j*5][count] = 1;
					temp_object[j*5+3][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "a"){
					temp_object[j*5+1][count] = 1;
					temp_object[j*5+3][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "b"){
					temp_object[j*5][count] = 1;
					temp_object[j*5+1][count] = 1;
					temp_object[j*5+3][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "c"){
					temp_object[j*5+2][count] = 1;
					temp_object[j*5+3][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "d"){
					temp_object[j*5][count] = 1;
					temp_object[j*5+2][count] = 1;
					temp_object[j*5+3][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "e"){
					temp_object[j*5+1][count] = 1;
					temp_object[j*5+2][count] = 1;
					temp_object[j*5+3][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "f"){
					temp_object[j*5][count] = 1;
					temp_object[j*5+1][count] = 1;
					temp_object[j*5+2][count] = 1;
					temp_object[j*5+3][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "g"){
					temp_object[j*5+4][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "h"){
					temp_object[j*5][count] = 1;
					temp_object[j*5+4][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "i"){
					temp_object[j*5+1][count] = 1;
					temp_object[j*5+4][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "j"){
					temp_object[j*5][count] = 1;
					temp_object[j*5+1][count] = 1;
					temp_object[j*5+4][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "k"){
					temp_object[j*5+2][count] = 1;
					temp_object[j*5+4][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "l"){
					temp_object[j*5][count] = 1;
					temp_object[j*5+2][count] = 1;
					temp_object[j*5+4][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "m"){
					temp_object[j*5+1][count] = 1;
					temp_object[j*5+2][count] = 1;
					temp_object[j*5+4][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "n"){
					temp_object[j*5][count] = 1;
					temp_object[j*5+1][count] = 1;
					temp_object[j*5+2][count] = 1;
					temp_object[j*5+4][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "o"){
					temp_object[j*5+3][count] = 1;
					temp_object[j*5+4][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "p"){
					temp_object[j*5][count] = 1;
					temp_object[j*5+3][count] = 1;
					temp_object[j*5+4][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "q"){
					temp_object[j*5+1][count] = 1;
					temp_object[j*5+3][count] = 1;
					temp_object[j*5+4][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "r"){
					temp_object[j*5][count] = 1;
					temp_object[j*5+1][count] = 1;
					temp_object[j*5+3][count] = 1;
					temp_object[j*5+4][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "s"){
					temp_object[j*5+2][count] = 1;
					temp_object[j*5+3][count] = 1;
					temp_object[j*5+4][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "t"){
					temp_object[j*5][count] = 1;
					temp_object[j*5+2][count] = 1;
					temp_object[j*5+3][count] = 1;
					temp_object[j*5+4][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "u"){
					temp_object[j*5+1][count] = 1;
					temp_object[j*5+2][count] = 1;
					temp_object[j*5+3][count] = 1;
					temp_object[j*5+4][count] = 1;
					count++;
				}
				else if (cont_rows[j][k] == "v"){
					temp_object[j*5][count] = 1;
					temp_object[j*5+1][count] = 1;
					temp_object[j*5+2][count] = 1;
					temp_object[j*5+3][count] = 1;
					temp_object[j*5+4][count] = 1;
					count++;
				}
			}
		}
	return temp_object;
}
		
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
			