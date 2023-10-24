//
// Created by rVaida on 24/10/2023.
//

#include "Reader.h"


Reader::Reader(int fileNumber, int strategyCode) {
    if(strategyCode == 0)
}

int Reader::getN() const {
    return this->n;
}

int Reader::getM() const {
    return this->m;
}

int**& Reader::getMatrix() {
    return this->matrix;
}

int Reader::getK() const {
    return this->k;
}

int**& Reader::getConvolutionalMatrix() {
    return this->convolutionalMatrix;
}
