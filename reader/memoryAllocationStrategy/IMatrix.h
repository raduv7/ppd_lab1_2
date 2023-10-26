//
// Created by rVaida on 26/10/2023.
//

#ifndef LAB1_2_IMATRIX_H
#define LAB1_2_IMATRIX_H

using namespace std;

class IMatrix {
public:
    virtual int& at(int line, int col) = 0;
};

#endif //LAB1_2_IMATRIX_H
