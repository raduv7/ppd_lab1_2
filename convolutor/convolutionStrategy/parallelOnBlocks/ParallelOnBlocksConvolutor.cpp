//
// Created by Radu Andrei Vaida on 25.10.2023.
//

#include <thread>
#include "ParallelOnBlocksConvolutor.h"

IMatrix& ParallelOnBlocksConvolutor::convolute() {
    vector<thread> threads;

    for (int i = 0; i < threadsCnt; ++i) {
        threads.push_back(thread([this, i]() {
            int startIndex = i * n * m / threadsCnt;
            int endIndex = (i + 1) * n * m / threadsCnt;
            for(int index = startIndex; index < endIndex; ++index) {
                int x = index / m;
                int y = index % m;
                this->convoluteElementInMatrix(x, y);
            }
        }));
    }

    for (auto& th : threads) {
        th.join();
    }

    return resultMatrix;
}
