//
// Created by rVaida on 24/10/2023.
//

#ifndef LAB1_2_STATICMEMORYALLOCATION_H
#define LAB1_2_STATICMEMORYALLOCATION_H

#include <vector>
#include "IMemoryAllocationStrategy.h"

using namespace std;

class StaticMemoryAllocation : IMemoryAllocationStrategy {
private:
    vector<vector<int>> matrix;
public:
    StaticMemoryAllocation(int lines, int cols) : matrix(lines, vector<int>(cols, 0)) {}

    vector<vector<int>>& getMatrix() override;
};


#endif //LAB1_2_STATICMEMORYALLOCATION_H
