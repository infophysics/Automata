#include <pybind11/pybind11.h>
#include "Automata.h"
#include <pybind11/stl_bind.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>



namespace py = pybind11;

PYBIND11_MODULE(automata, m) {
  //	Binding for YieldResult struct
  py::class_<Cell>(m, "Cell", py::dynamic_attr())
		.def(py::init<int>())
		.def_readwrite("m_State", &Cell::m_State)
		;
  //	Binding for the NESTcalc class
  py::class_<Automata>(m, "Automata")
  	  .def(py::init<>())
	  .def(py::init<int>())
	  .def(py::init<int, int>())
	  .def(py::init<int, int, int>())
	  .def(py::init<int, int, int, int>())
	  .def(py::init<int, int, int, int, float>())
	  .def(py::init<int, int, int, int, float, int>())

	  //	setters
  	  .def("setBoundary", &Automata::setBoundary)
	  .def("setRule", &Automata::setRule)
	  .def("setDensity", &Automata::setDensity)
	  .def("setTime", &Automata::setTime)
  	  //	set cell values
	  .def("setCells", &Automata::setCells)
  	  //	getters
	  .def("getBoundary", &Automata::getBoundary)
	  .def("getRule", &Automata::getRule)
	  .def("getDensity", &Automata::getDensity)
	  .def("getTime", &Automata::getTime)
  	  //	state determination
  	  .def("findOneDimensionalState", &Automata::findOneDimensionalState)
  	  .def("findTwoDimensionalvonNeumannState", &Automata::findTwoDimensionalvonNeumannState)
	  //.def("findOneDimensionalState2", &Automata::findOneDimensionalState2)
	  //.def("findTwoDimensionalvonNeumannState2", &Automata::findTwoDimensionalvonNeumannState2)
	  //.def("findTwoDimensionalMooreState2", &Automata::findTwoDimensionalMooreState2)
	  //	updating cells
  	  .def("findOneDimensionalUpdateRule", &Automata::findOneDimensionalUpdateRule)
	  //.def("findTwoDimensionalvonNeumannUpdateRule", &Automata::findTwoDimensionalvonNeumannUpdateRule)
	  //.def("findTwoDimensionalvonNeumannUpdateRule2", &Automata::findTwoDimensionalvonNeumannUpdateRule2)
	  //.def("findTwoDimensionalMooreUpdateRule2", &Automata::findTwoDimensionalMooreUpdateRule2)
	  .def("updateOneDimensionalCells", &Automata::updateOneDimensionalCells)
	  //.def("updateTwoDimensionalCells", &Automata::updateTwoDimensionalCells)
	  //	printing
	  .def("printCells", &Automata::printCells)
	  .def("displayOneDimensionalCells", &Automata::displayOneDimensionalCells)
	  //.def("displayTwoDimensionalCells", &Automata::displayTwoDimensionalCells)  	  
	  //	initializers
  	  .def("initializeOneDimensionalEmptyCells", &Automata::initializeOneDimensionalEmptyCells)
	  .def("initializeOneDimensionalCells", &Automata::initializeOneDimensionalCells)
	  //.def("initializeCells", py::overload_cast<float>(&Automata::initializeCells))
  	  //	generators
  	  .def("generateOneDimensionalSequence", &Automata::generateOneDimensionalSequence)
  	  //	save sequence to file
  	  .def("saveSequenceToFile", &Automata::saveSequenceToFile)
	  ;
}
