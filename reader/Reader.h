//
// Created by rVaida on 24/10/2023.
//

#ifndef LAB1_2_READER_H
#define LAB1_2_READER_H

#include <vector>
#include "memoryAllocationStrategy/IMemoryAllocationStrategy.h"
#include "memoryAllocationStrategy/IMatrix.h"

using namespace std;

class Reader {
private:
    int n, m, k;
    vector<vector<int>> *matrix, *convolutionalMatrix;
    IMatrix *inputMatrix, *resultMatrix;

    int insideOnY(int j);
    void borderMatrix();
    void copyToInputMatrix();

public:
    Reader(int fileNumber, int strategyCode);

    int getN() const;
    int getM() const;
    IMatrix& getInputMatrix();
    IMatrix& getResultMatrix();
    int getK() const;
    vector<vector<int>>* getConvolutionalMatrix();
};


#endif //LAB1_2_READER_H
