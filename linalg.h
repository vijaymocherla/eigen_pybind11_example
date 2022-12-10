#ifdef EIGEN_USE_MKL
#include "mkl_lapacke.h"
#else
#include "lapacke.h"
#endif
#include <Eigen/Eigenvalues>
#include <Eigen/Dense>
#include <iostream>

using namespace std;
// Use RowMatrixXd instead of MatrixXd to pass a RowMajor array to C++ functions from python
using RowMatrixXd = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>;

//Declaring the functions
std::tuple<Eigen::VectorXd, Eigen::MatrixXd> diagonalise(Eigen::Ref<RowMatrixXd> matrix);
