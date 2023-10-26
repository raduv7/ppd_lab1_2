//
// Created by Radu Andrei Vaida on 25.10.2023.
//

#include "ParallelOnLinesConvolutor.h"
#include <thread>

using namespace std;

IMatrix& ParallelOnLinesConvolutor::convolute() {
    vector<thread> threads;

    for (int i = 0; i < threadsCnt; ++i) {
        threads.push_back(thread([this, i]() {
            int startLine = i * n / threadsCnt;
            int endLine = (i + 1) * n / threadsCnt;
            for(int i = startLine; i < endLine; ++i) {
                for(int j = 0; j < m; ++j) {
                    this->convoluteElementInMatrix(i, j);
                }
            }
        }));
    }

    for (auto& th : threads) {
        th.join();
    }

    return resultMatrix;
}
