/* 
    Module binding for Car2DPhysics...
*/

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <iostream>

#include "Trajectory.h"
#include "BaseCar.h"
#include "FreeCar.h"
#include "BenchmarkCircuit8.h"


namespace py = pybind11;

void module_init()
{
    std::cout << "Car2DPhysics module init..." << std::endl;

}

PYBIND11_MODULE(car2dphysics, m)
{
    m.doc() = R"pbdoc(
        car2dphysics plugin
        -------------------
        .. currentmodule:: cmake_example
        .. autosummary::
           :toctree: _generate
           add
           subtract
    )pbdoc";

    m.def("init", &module_init);

    py::class_<Trajectory>(m, "Trajectory")
        // .def(py::init<>())
        .def(py::init< std::list<float>* >())
        // .def("add", &ComplexNumber::add)
        .def("GetLength", &Trajectory::GetLength)
        // .def("__repr__",[](const ComplexNumber &c) {return "<sandbox Complex value=(" + STRINGIFY(c._x) + "," + STRINGIFY(c._y) + ")"; }
        .def("__repr__", &Trajectory::Repr)
        // .def(pybind11::self + pybind11::self)
        ;

    py::class_<BenchmarkCircuit8>(m,"BenchmarkCircuit8")
        .def(py::init<>())
        .def("Step", &BenchmarkCircuit8::Step)
        .def("GetFreeCar", &BenchmarkCircuit8::GetFreeCar)
        ;

    py::class_<BaseCar>(m,"BaseCar")
        .def("GetPosition",[](BaseCar &c){b2Vec2 p=c.GetPosition(); return std::tuple<float,float,float>{p.x,p.y,c.GetAngle()};})
        ;

    py::class_<FreeCar,BaseCar>(m,"FreeCar")
        .def("Throttle",&FreeCar::Throttle)
        .def("Brake",&FreeCar::Brake)
        .def("Turn",&FreeCar::Turn)
        ;


#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif    
}
