#include "linalg.h"
#include "lapacke.h"


std::tuple<Eigen::VectorXd, Eigen::MatrixXd> diagonalise(Eigen::Ref<RowMatrixXd> matrix) {
    // Lets call Eigen solver from Eigen to diagonalise matrix     
    char jobz = 'V';    // 'V':  Compute eigenvalues and eigenvectors.
    char uplo = 'U';    // 'U':  Upper triangle of A is stored.
    int N = matrix.rows();          // The order of the matrix A,  with n >= 0.
    int lda, lwork, info;
    lda = N;        // The leading dimension of the array A,  LDA >= max(1,N).
    lwork = N * N;  // The length of the array work, lwork >= max(1,3*N-1).
    Eigen::VectorXd evals(N);
    Eigen::MatrixXd evecs(N,N);
    evecs = matrix;     
    info = LAPACKE_dsyev(LAPACK_ROW_MAJOR, 'V', 'U', lda, &evecs(0, 0), lwork, &evals(0));
    // initialize <vector> eigavals and <matrix> eigvecs to pass to <tuple> result
    std::tuple<Eigen::VectorXd, Eigen::MatrixXd> result(evals, evecs);
    return result;
}

