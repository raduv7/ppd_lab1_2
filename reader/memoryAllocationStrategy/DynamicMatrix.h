//
// Created by rVaida on 26/10/2023.
//

#ifndef LAB1_2_DYNAMICMATRIX_H
#define LAB1_2_DYNAMICMATRIX_H


#include "IMatrix.h"

class DynamicMatrix : public IMatrix {
private:
    int lines;
    int cols;
    int **matrix;
public:
    DynamicMatrix(int lines, int cols) : lines(lines), cols(cols) {
        matrix = new int *[lines];
        for (int i = 0; i < lines; i++) {
            matrix[i] = new int[cols];
        }
    }

    int &at(int line, int col) override {
        return matrix[line][col];
    }
};


#endif //LAB1_2_DYNAMICMATRIX_H
