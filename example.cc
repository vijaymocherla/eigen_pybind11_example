#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/numpy.h>
#include "linalg.h"

namespace py = pybind11;

PYBIND11_MODULE(example, m){
    m.doc() = "A pybind11 example module";
    m.def("diagonalise", &diagonalise, "A function that diagonalises a matrix");
}
