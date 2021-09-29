#include <iostream>
#include <vector>
#include <numeric>
#include "arr2d.hpp"

class arr3d
{
    std::vector<double> buffer;
    int dims[3];

    public:
        arr3d(int i, int j, int k);
        std::vector<double> slice_1d(int j, int k);
        arr2d slice_2d(int i);
        double operator()(int i, int j, int k) const;
        double& operator()(int i, int j, int k);
};

arr3d::arr3d(int N, int M, int O){
    buffer = std::vector<double> (N*M*O);
    std::iota(buffer.begin(), buffer.end(), 0); // test case
    dims[0] = N;
    dims[1] = M;
    dims[2] = O;
}

double arr3d::operator()(int i, int j, int k) const {
    return buffer[i * dims[1] * dims[2] + j * dims[2] + k];
}

double& arr3d::operator()(int i, int j, int k) {
    return buffer[i * dims[1] * dims[2] + j * dims[2] + k];
}

std::vector<double> arr3d::slice_1d(int j, int k) {
    std::vector<double> output_arr(dims[0]);
    for (int i = 0; i < dims[0]; i++) {
        output_arr[i] = buffer[i * dims[1] * dims[2] + j * dims[2] + k];
    }
    return output_arr;
}


arr2d arr3d::slice_2d(int i) {
    arr2d output_arr(dims[1], dims[2]);
    for (int j = 0; j < dims[1]; j++){
        for (int k = 0; k < dims[2]; k++){
            output_arr(j, k) = buffer[i * dims[1] * dims[2] + j * dims[2] + k];
        }
    }
    return output_arr;
}
