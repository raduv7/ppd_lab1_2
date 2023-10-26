//
// Created by rVaida on 24/10/2023.
//

#ifndef LAB1_2_STATICMEMORYALLOCATION_H
#define LAB1_2_STATICMEMORYALLOCATION_H

#include <vector>
#include "IMemoryAllocationStrategy.h"

using namespace std;

class StaticMemoryAllocation : public IMemoryAllocationStrategy {
private:
    int matrix0[10][10];
    int matrix1[1000][1000];
    int matrix2[10][10000];
    int matrix3[10000][10];
//    vector<vector<int>> matrix;
public:
    StaticMemoryAllocation(int lines, int cols) : matrix(lines, vector<int>(cols, 0)) {}

    int& getMatrix();
};


#endif //LAB1_2_STATICMEMORYALLOCATION_H
