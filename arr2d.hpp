#include <iostream>
#include <vector>
#include <numeric>

class arr2d
{
    std::vector<double> buffer;
    int dims[2];

    public:
        arr2d(int i, int j);
        double operator()(int i, int j) const;
        double& operator()(int i, int j);
};

arr2d::arr2d(int N, int M){
    buffer = std::vector<double> (N*M);
    std::fill(buffer.begin(), buffer.end(), 0); // test case
    dims[0] = N;
    dims[1] = M;
}

double arr2d::operator()(int i, int j) const {
    return buffer[i * dims[1] + j];
}

double& arr2d::operator()(int i, int j) {
    return buffer[i * dims[1] + j];
}
