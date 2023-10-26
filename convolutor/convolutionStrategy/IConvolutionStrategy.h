//
// Created by rVaida on 24/10/2023.
//

#ifndef LAB1_2_ICONVOLUTIONSTRATEGY_H
#define LAB1_2_ICONVOLUTIONSTRATEGY_H

#include <vector>
#include "../../reader/Reader.h"

using namespace std;

class IConvolutionStrategy {
private:
    Reader *reader;

protected:
    int n, m, k;
    IMatrix &resultMatrix;

    void convoluteUnit(int i, int j, int di, int dj) {
        this->resultMatrix.at(i, j) +=
                this->reader->getInputMatrix().at(i + di, j + dj) *
                this->reader->getConvolutionalMatrix()->at(di).at(dj);
    }

    void convoluteElementInMatrix(int i, int j) {
        for(int di = 0; di < this->reader->getK(); di++) {
            for(int dj = 0; dj < this->reader->getK(); dj++) {
                this->convoluteUnit(i, j, di, dj);
            }
        }
    }

public:
    IConvolutionStrategy(Reader *reader) : resultMatrix(reader->getResultMatrix()) {
        this->reader = reader;
        this->n = reader->getN();
        this->m = reader->getM();
        this->k = reader->getK();
    }

    virtual IMatrix& convolute() = 0;
};


#endif //LAB1_2_ICONVOLUTIONSTRATEGY_H
