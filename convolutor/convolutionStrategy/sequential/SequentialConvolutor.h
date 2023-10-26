//
// Created by Radu Andrei Vaida on 25.10.2023.
//

#ifndef LAB1_2_SEQUENTIALCONVOLUTOR_H
#define LAB1_2_SEQUENTIALCONVOLUTOR_H


#include "../IConvolutionStrategy.h"

class SequentialConvolutor : public IConvolutionStrategy {
public:
    explicit SequentialConvolutor(Reader *reader) : IConvolutionStrategy(reader) { };

    IMatrix& convolute() override;
};


#endif //LAB1_2_SEQUENTIALCONVOLUTOR_H
