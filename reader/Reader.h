//
// Created by rVaida on 24/10/2023.
//

#ifndef LAB1_2_READER_H
#define LAB1_2_READER_H

#include <vector>

using namespace std;

class Reader {
private:
    int n, m, k;
    vector<vector<int>> matrix, convolutionalMatrix;

public:
    Reader(int fileNumber, int strategyCode);

    int getN() const;
    int getM() const;
    int**& getMatrix();
    int getK() const;
    int**& getConvolutionalMatrix();
};


#endif //LAB1_2_READER_H
