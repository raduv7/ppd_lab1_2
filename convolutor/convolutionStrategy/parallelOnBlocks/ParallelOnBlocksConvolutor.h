//
// Created by Radu Andrei Vaida on 25.10.2023.
//

#ifndef LAB1_2_PARALLELONBLOCKSCONVOLUTOR_H
#define LAB1_2_PARALLELONBLOCKSCONVOLUTOR_H


#include "../IConvolutionStrategy.h"

class ParallelOnBlocksConvolutor : public IConvolutionStrategy {
private:
    int threadsCnt;
public:
    explicit ParallelOnBlocksConvolutor(Reader *reader, int threadsCnt) : IConvolutionStrategy(reader) {
            this->threadsCnt = threadsCnt;
    };

    vector<vector<int>>* convolute() override;
};


#endif //LAB1_2_PARALLELONBLOCKSCONVOLUTOR_H
