#include <iostream>
#include "arr3d.hpp"


using namespace std;

int main(int argc, char *argv[]) {

    int N = 2;
    int M = 3;
    int O = 4;

    arr3d arr(N, M, O);

    for (int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for (int k = 0; k < O; k++){
                std::cout << arr(i, j, k) << " ";
            }
            std::cout << '\n';
        }
        std::cout << "\n";
    }

    std::vector<double> slice_vec;

    for (int j = 0; j < M; j++){
        for (int k = 0; k < O; k++){
            slice_vec = arr.slice_1d(j, k);
            for (auto i: slice_vec){
                std::cout << i << " ";
            }
            std::cout << "\n";
        }
    }

    return 0;
}
