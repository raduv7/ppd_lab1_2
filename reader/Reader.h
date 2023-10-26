//
// Created by rVaida on 24/10/2023.
//

#ifndef LAB1_2_READER_H
#define LAB1_2_READER_H

#include <vector>
#include "memoryAllocationStrategy/IMemoryAllocationStrategy.h"

using namespace std;

class Reader {
private:
    int n, m, k;
    vector<vector<int>> *matrix, *convolutionalMatrix;
    IMemoryAllocationStrategy *strategy;

    int insideOnY(int j);
    void borderMatrix();

public:
    Reader(int fileNumber, int strategyCode);

    int getN() const;
    int getM() const;
    vector<vector<int>>* getMatrix();
    int getK() const;
    vector<vector<int>>* getConvolutionalMatrix();
};


#endif //LAB1_2_READER_H
