//
// Created by Radu Andrei Vaida on 25.10.2023.
//

#include "ParallelHashConvolutor.h"
#include <thread>
#include <unordered_map>
#include <cmath>
#include <algorithm>

IMatrix& ParallelHashConvolutor::convolute() {
    vector<thread> threads;
    unordered_map<int, int> hashMap = populateHashMap();

    for (int i = 0; i < threadsCnt; ++i) {
        threads.push_back(thread([this, i, &hashMap]() {
            for (const auto& pair : hashMap) {
                if (pair.second == i) {
                    int x = pair.first / m;
                    int y = pair.first % m;
                    this->convoluteElementInMatrix(x, y);
                }
            }
        }));
    }

    for (auto& th : threads) {
        th.join();
    }

    return resultMatrix;
}

int ParallelHashConvolutor::hashMultiplicative(int value) {
    double A = (sqrt(5) - 1) / 2; // golden ratio fraction
    return static_cast<int>(threadsCnt * fmod(value * A, 1.0));
}

unordered_map<int, int> ParallelHashConvolutor::populateHashMapMultiplicative() {
    unordered_map<int, int> hashMap;

    for(int i = 0; i < n*m; ++i) {
        int hash = hashMultiplicative(i);
        hashMap[i] = hash;
    }

    return hashMap;
}

int ParallelHashConvolutor::hashBitwiseXor(int value) {
    int hash = value;
    hash = (hash ^ (hash >> 8)) & (threadsCnt - 1); // Assuming threadsCnt is a power of 2
    return hash;
}

unordered_map<int, int> ParallelHashConvolutor::populateHashMapBitwise() {
    unordered_map<int, int> hashMap;

    for(int i = 0; i < n*m; ++i) {
        int hash = hashBitwiseXor(i);
        hashMap[i] = hash;
    }

    return hashMap;
}

unordered_map<int, int> ParallelHashConvolutor::populateHashMap() {
    return populateHashMapMultiplicative();
    // return populateHashMapBitwise();
}
