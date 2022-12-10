import example
import numpy as np

def test_diagonalise():
    ndim = 300
    A = np.identity(ndim)
    # testing the c++ function
    eigvals, eigvecs = example.diagonalise(A)
    assert np.allclose(eigvals,np.ones(ndim)), "Eigenvalues are incorrect!"
    assert np.allclose(eigvecs,A), "Eigenvectors are all not equal!"

if __name__ == "__main__":
    
    test_diagonalise()
    print("Tests passed!\n")
