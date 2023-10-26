//
// Created by rVaida on 24/10/2023.
//

#include <string>
#include <fstream>
#include "Reader.h"
#include "memoryAllocationStrategy/DynamicMemoryAllocation.h"
#include "memoryAllocationStrategy/StaticMemoryAllocation.h"
#include "memoryAllocationStrategy/DynamicMatrix.h"
#include "memoryAllocationStrategy/StaticMatrix.h"

using namespace std;

Reader::Reader(int fileNumber, int strategyCode) {
    ifstream fin("input/data" + to_string(fileNumber) + ".txt");

    fin >> this->n >> this->m >> this->k;

    if(strategyCode == 0) {
        this->inputMatrix = new DynamicMatrix(n + k - 1, m + k - 1);
        this->resultMatrix = new DynamicMatrix(n + k - 1, m + k - 1);
    } else {
        this->inputMatrix= new StaticMatrix(n + k - 1, m + k - 1);
        this->resultMatrix= new StaticMatrix(n + k - 1, m + k - 1);
    }


    this->matrix = new vector<vector<int>>(n + k - 1, vector<int>(m + k - 1, 0));

    for(int i = 0; i < this->n; i++) {
        for(int j = 0; j < this->m; j++) {
            fin >> this->matrix->at(i).at(j);
        }
    }

    borderMatrix();

    this->convolutionalMatrix = new vector<vector<int>>(this->n, vector<int>(this->m, 0));

    for(int i = 0; i < this->k; i++) {
        for(int j = 0; j < this->k; j++) {
            fin >> this->convolutionalMatrix->at(i).at(j);
        }
    }

    copyToInputMatrix();
}

int Reader::insideOnY(int j) {
    int kHalf = k / 2;
    if(j < kHalf) {
        return kHalf;
    }
    if(j >= m + kHalf) {
        return m + kHalf - 1;
    }
    return j;
}

void Reader::borderMatrix() {
    int kHalf = k / 2;
    for(int i = 0; i < kHalf; ++i) {
        for(int j = 0; j < m + k - 1; ++j) {
            matrix->at(i).at(j) = matrix->at(kHalf).at(insideOnY(j));
            matrix->at(n + k - 2 - i).at(j) = matrix->at(n + kHalf - 1).at(insideOnY(j));
        }
    }
    for(int j = 0; j < kHalf; ++j) {
        for(int i = kHalf; i < n + kHalf; ++i) {
            matrix->at(i).at(j) = matrix->at(i).at(kHalf);
            matrix->at(i).at(m + k - 2 - j) = matrix->at(i).at(n + kHalf - 1);
        }
    }
}

int Reader::getN() const {
    return this->n;
}

int Reader::getM() const {
    return this->m;
}

IMatrix& Reader::getInputMatrix() {
    return *this->inputMatrix;
}

IMatrix& Reader::getResultMatrix() {
    return *this->resultMatrix;
}

int Reader::getK() const {
    return this->k;
}

vector<vector<int>>* Reader::getConvolutionalMatrix() {
    return this->convolutionalMatrix;
}

void Reader::copyToInputMatrix() {
    for(int i = 0; i < this->n + this->k - 1; i++) {
        for(int j = 0; j < this->m + this->k - 1; j++) {
            this->inputMatrix->at(i, j) = this->matrix->at(i).at(j);
        }
    }
}
