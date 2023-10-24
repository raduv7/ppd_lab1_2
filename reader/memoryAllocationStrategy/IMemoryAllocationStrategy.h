//
// Created by rVaida on 24/10/2023.
//

#ifndef LAB1_2_IMEMORYALLOCATIONSTRATEGY_H
#define LAB1_2_IMEMORYALLOCATIONSTRATEGY_H

#include <vector>

using namespace std;

class IMemoryAllocationStrategy {
public:
    virtual vector<vector<int>>& getMatrix() = 0;
};

#endif //LAB1_2_IMEMORYALLOCATIONSTRATEGY_H