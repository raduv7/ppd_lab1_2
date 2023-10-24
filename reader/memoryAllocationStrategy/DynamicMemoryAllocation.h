//
// Created by rVaida on 24/10/2023.
//

#ifndef LAB1_2_DYNAMICMEMORYALLOCATION_H
#define LAB1_2_DYNAMICMEMORYALLOCATION_H


#include "IMemoryAllocationStrategy.h"

class DynamicMemoryAllocation : IMemoryAllocationStrategy {
private:
    vector<vector<int>> matrix;
public:
    DynamicMemoryAllocation(int lines, int cols) {
        matrix = * new vector(lines, vector<int>(cols, 0));
    }
    vector<vector<int>>& getMatrix() override;
};


#endif //LAB1_2_DYNAMICMEMORYALLOCATION_H
