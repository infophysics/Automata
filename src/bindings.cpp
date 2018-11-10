#include <pybind11/pybind11.h>
#include "Automata.h"
#include "Conway.h"
#include <pybind11/stl_bind.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>



namespace py = pybind11;

PYBIND11_MODULE(automata, m) {
  //	Binding for Cell struct
  py::class_<Cell>(m, "Cell", py::dynamic_attr())
		.def(py::init<int, int>())
		.def_readwrite("m_State", &Cell::m_State)
		.def_readwrite("m_NumStates", &Cell::m_NumStates)
		;
  //	Binding for the Automata class
  py::class_<Automata>(m, "Automata")
  	  .def(py::init<>())
	  .def(py::init<int, int, int>())
	  .def(py::init<int, int, int, int>())
	  .def(py::init<int, int, int, int, int>())
	  .def(py::init<int, int, int, int, int, int>())
	  .def(py::init<int, int, int, int, int, int, float>())
	  .def(py::init<int, int, int, int, int, int, float, int>())

	  //	setters
	  .def("setDim", &Automata::setDim)
	  .def("setSize", &Automata::setSize)
	  .def("setNumStates", &Automata::setNumStates)
  	  .def("setBoundary", &Automata::setBoundary)
	  .def("setRule", &Automata::setRule)
	  .def("setType", &Automata::setType)
	  .def("setDensity", &Automata::setDensity)
	  .def("setTime", &Automata::setTime)
  	  //	set cell values
	  .def("setCells", (void (Automata::*)(std::vector<std::vector<int> >)) &Automata::setCells)
	  .def("setCells", (void (Automata::*)(std::vector<std::vector<Cell> >)) &Automata::setCells)
  	  //	getters
	  .def("getBoundary", &Automata::getBoundary)
	  .def("getRule", &Automata::getRule)
	  .def("getDensity", &Automata::getDensity)
	  .def("getTime", &Automata::getTime)
	  .def("getCells", &Automata::getCells)
	  .def("getState", &Automata::getState)
  	  //	state determination
  	  .def("findOneDimensionalState", &Automata::findOneDimensionalState)
	  .def("findOneDimensionalState_2State", &Automata::findOneDimensionalState_2State)
	  .def("findOneDimensionalState_2State2", &Automata::findOneDimensionalState_2State2)
	  .def("findOneDimensionalState_3State2", &Automata::findOneDimensionalState_3State2)
	  .def("findTwoDimensionalvonNeumannState_2State", &Automata::findTwoDimensionalvonNeumannState_2State)
	  .def("findTwoDimensionalvonNeumannState_2State2", &Automata::findTwoDimensionalvonNeumannState_2State2)

	  //.def("findTwoDimensionalMooreState2", &Automata::findTwoDimensionalMooreState2)
	  //	updating cells
  	  .def("findOneDimensionalUpdateRule", &Automata::findOneDimensionalUpdateRule)
	  .def("findOneDimensionalUpdateRule_2State", &Automata::findOneDimensionalUpdateRule_2State)
	  .def("findOneDimensionalUpdateRule_3State2", &Automata::findOneDimensionalUpdateRule_3State2)
	  .def("findTwoDimensionalvonNeumannUpdateRule_2State", &Automata::findTwoDimensionalvonNeumannUpdateRule_2State)
	  .def("findTwoDimensionalvonNeumannUpdateRule_2State2", &Automata::findTwoDimensionalvonNeumannUpdateRule_2State2)
	  //.def("findTwoDimensionalMooreUpdateRule2", &Automata::findTwoDimensionalMooreUpdateRule2)
	  .def("updateOneDimensionalCells", &Automata::updateOneDimensionalCells)
	  .def("updateOneDimensionalCells_2State", &Automata::updateOneDimensionalCells_2State)
	  .def("updateOneDimensionalCells_3State2", &Automata::updateOneDimensionalCells_3State2)
	  .def("updateTwoDimensionalCells", &Automata::updateTwoDimensionalCells)
	  .def("updateTwoDimensionalvonNeumannCells_2State", &Automata::updateTwoDimensionalvonNeumannCells_2State)
	  .def("updateTwoDimensionalvonNeumannCells_2State2", &Automata::updateTwoDimensionalvonNeumannCells_2State2)
	  //	printing
	  .def("printCells", &Automata::printCells)
	  .def("displayOneDimensionalCells_2State", &Automata::displayOneDimensionalCells_2State)
	  .def("displayOneDimensionalCells_3State", &Automata::displayOneDimensionalCells_3State)  
	  .def("displayTwoDimensionalCells_2State", &Automata::displayTwoDimensionalCells_2State)  	  
	  //	initializers
  	  .def("initializeOneDimensionalEmptyCells", &Automata::initializeOneDimensionalEmptyCells)
	  .def("initializeOneDimensionalCells", &Automata::initializeOneDimensionalCells)
	  .def("initializeTwoDimensionalEmptyCells", &Automata::initializeTwoDimensionalEmptyCells)
	  .def("initializeTwoDimensionalCells", &Automata::initializeTwoDimensionalCells)
	  //.def("initializeCells", py::overload_cast<float>(&Automata::initializeCells))
  	  //	generators
  	  .def("generateOneDimensionalSequence", &Automata::generateOneDimensionalSequence)
	  .def("generateTwoDimensionalSequence", &Automata::generateTwoDimensionalSequence)
	  .def("generateTwoDimensionalSequence_2State", &Automata::generateTwoDimensionalSequence_2State)
  	  //	save sequence to file
  	  .def("saveOneDimensionalSequenceToFile", &Automata::saveOneDimensionalSequenceToFile)
	  .def("saveTwoDimensionalSequenceToFile", &Automata::saveTwoDimensionalSequenceToFile)
	  ;  		  		
  
  py::class_<Conway, Automata>(m, "Conway")
      .def(py::init<>())
	  .def(py::init<int, int, float, int>())
	  .def(py::init<std::string, int, int, float, int>())
	  .def("placeObject", &Conway::placeObject)
	  .def("generateObject", &Conway::generateObject)
	  .def("chipSequence", &Conway::chipSequence)
	  ;  
}

