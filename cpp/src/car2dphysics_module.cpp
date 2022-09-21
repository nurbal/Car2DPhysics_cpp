/* 
    Module binding for Car2DPhysics...
*/

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "Trajectory.h"


namespace py = pybind11;


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

    py::class_<Trajectory>(m, "Trajectory")
        // .def(py::init<>())
        .def(py::init< std::list<float>* >())
        // .def("add", &ComplexNumber::add)
        .def("GetLength", &Trajectory::GetLength)
        // .def("__repr__",[](const ComplexNumber &c) {return "<sandbox Complex value=(" + STRINGIFY(c._x) + "," + STRINGIFY(c._y) + ")"; }
        .def("__repr__", &Trajectory::Repr)
        // .def(pybind11::self + pybind11::self)
        ;

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif    
}
