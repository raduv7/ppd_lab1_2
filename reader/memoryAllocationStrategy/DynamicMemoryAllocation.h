//
// Created by rVaida on 24/10/2023.
//

#ifndef LAB1_2_DYNAMICMEMORYALLOCATION_H
#define LAB1_2_DYNAMICMEMORYALLOCATION_H


#include "IMemoryAllocationStrategy.h"

class DynamicMemoryAllocation : public IMemoryAllocationStrategy {
private:
//    vector<vector<int>> *matrix;
    int*[] matrix;
public:
    DynamicMemoryAllocation(int lines, int cols) {
//        matrix = new vector(lines, vector<int>(cols, 0));
        matrix = new int[lines][cols];
    }

    vector<vector<int>>* getMatrix() override;
};


#endif //LAB1_2_DYNAMICMEMORYALLOCATION_H
