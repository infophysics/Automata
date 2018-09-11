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
  	  //	updating cells
  	  .def("findUpdateRule", &Automata::findUpdateRule)
	  .def("updateOneDimensionalCells", &Automata::updateOneDimensionalCells)
	  //	printing
	  .def("printCells", &Automata::printCells)
	  .def("displayOneDimensionalCells", &Automata::displayOneDimensionalCells)
  	  //	initializers
  	  .def("initializeEmptyCells", &Automata::initializeEmptyCells)
	  .def("initializeCells", &Automata::initializeCells)
	  //.def("initializeCells", py::overload_cast<float>(&Automata::initializeCells))
  	  //	generators
  	  .def("generateSequence", &Automata::generateSequence)
  	  //	save sequence to file
  	  .def("saveSequenceToFile", &Automata::saveSequenceToFile)
	  ;
}
