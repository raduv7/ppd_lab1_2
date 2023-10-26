//
// Created by Radu Andrei Vaida on 25.10.2023.
//

#ifndef LAB1_2_PARALLELHASHCONVOLUTOR_H
#define LAB1_2_PARALLELHASHCONVOLUTOR_H


#include <unordered_map>
#include "../IConvolutionStrategy.h"

using namespace std;

class ParallelHashConvolutor : public IConvolutionStrategy {
private:
    int threadsCnt;
public:
    explicit ParallelHashConvolutor(Reader *reader, int threadsCnt) : IConvolutionStrategy(reader) {
            this->threadsCnt = threadsCnt;
    };

    vector<vector<int>>* convolute() override;

    int hashMultiplicative(int value);

    std::__1::unordered_map<int, int> populateHashMapMultiplicative();

    int hashBitwiseXor(int value);

    unordered_map<int, int> populateHashMapBitwise();

    unordered_map<int, int> populateHashMap();
};


#endif //LAB1_2_PARALLELHASHCONVOLUTOR_H
