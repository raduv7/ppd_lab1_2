//
// Created by rVaida on 26/10/2023.
//

#ifndef LAB1_2_STATICMATRIX_H
#define LAB1_2_STATICMATRIX_H


#include "IMatrix.h"

class StaticMatrix : public IMatrix {
private:
    int lines;
    int cols;
    int matrix[10000][10000];
public:
    StaticMatrix(int lines, int cols) : lines(lines), cols(cols) {}

    int& at(int line, int col) override {
        return matrix[line][col];
    }
};





#endif //LAB1_2_STATICMATRIX_H
