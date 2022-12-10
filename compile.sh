LAPACK_FLAGS=('-D EIGEN_USE_LAPACKE=1 -lm -lblas -llapack -llapacke')
g++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) linalg.cc example.cc -o example$(python3-config --extension-suffix) -fopenmp  ${LAPACK_FLAGS[@]}

python test.py > test.out  

