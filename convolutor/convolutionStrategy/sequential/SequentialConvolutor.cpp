//
// Created by Radu Andrei Vaida on 25.10.2023.
//

#include "SequentialConvolutor.h"

vector<vector<int>> *SequentialConvolutor::convolute() {
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            convoluteElementInMatrix(i, j);
        }
    }

    return resultMatrix;
}
