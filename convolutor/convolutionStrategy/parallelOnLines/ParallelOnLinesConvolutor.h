//
// Created by Radu Andrei Vaida on 25.10.2023.
//

#ifndef LAB1_2_PARALLELONLINESCONVOLUTOR_H
#define LAB1_2_PARALLELONLINESCONVOLUTOR_H


#include "../IConvolutionStrategy.h"

class ParallelOnLinesConvolutor : public IConvolutionStrategy {
private:
    int threadsCnt;
public:
    explicit ParallelOnLinesConvolutor(Reader *reader, int threadsCnt) : IConvolutionStrategy(reader) {
        this->threadsCnt = threadsCnt;
    };

    IMatrix& convolute() override;
};


#endif //LAB1_2_PARALLELONLINESCONVOLUTOR_H
