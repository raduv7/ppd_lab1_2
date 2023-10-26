//
// Created by rVaida on 24/10/2023.
//

#ifndef LAB1_2_CONVOLUTOR_H
#define LAB1_2_CONVOLUTOR_H


#include <stdexcept>
#include "../reader/Reader.h"
#include "convolutionStrategy/IConvolutionStrategy.h"
#include "convolutionStrategy/sequential/SequentialConvolutor.h"
#include "convolutionStrategy/parallelOnLines/ParallelOnLinesConvolutor.h"
#include "convolutionStrategy/parallelOnBlocks/ParallelOnBlocksConvolutor.h"
#include "convolutionStrategy/parallelHash/ParallelHashConvolutor.h"

using namespace std;

class Convolutor {
private:
    IConvolutionStrategy *convolutionStrategy;
public:
    Convolutor(Reader *reader, int threadsCnt, int strategyCode) {
        if(strategyCode == 0) {
            this->convolutionStrategy = new SequentialConvolutor(reader);
        }
        else if(strategyCode == 1) {
            this->convolutionStrategy = new ParallelOnLinesConvolutor(reader, threadsCnt);
        }
        else if(strategyCode == 2) {
            this->convolutionStrategy = new ParallelOnBlocksConvolutor(reader, threadsCnt);
        }
        else if(strategyCode == 3) {
            this->convolutionStrategy = new ParallelHashConvolutor(reader, threadsCnt);
        }
        else {
            throw runtime_error("invalid convolution strategy code");
        }
    }

    IMatrix& convolute() {
        return this->convolutionStrategy->convolute();
    }
};


#endif //LAB1_2_CONVOLUTOR_H
