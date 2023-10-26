//
// Created by rVaida on 24/10/2023.
//

#ifndef LAB1_2_CONVOLUTOR_H
#define LAB1_2_CONVOLUTOR_H


#include "../reader/Reader.h"
#include "convolutionStrategy/IConvolutionStrategy.h"
#include "convolutionStrategy/sequential/SequentialConvolutor.h"

class Convolutor {
private:
    IConvolutionStrategy *convolutionStrategy;
public:
    Convolutor(Reader *reader, int threadsCnt, int strategyCode) {
        if(strategyCode == 0) {
            this->convolutionStrategy = new SequentialConvolutor(reader);
        }
        else if(strategyCode == 1) {
            ;
        }
        else if(strategyCode == 2) {
            ;
        }
        else if(strategyCode == 3) {
            ;
        }
        else {
            throw runtime_error("invalid convolution strategy code");
        }
    }

    vector<vector<int>>* convolute() {
        return this->convolutionStrategy->convolute();
    }
};


#endif //LAB1_2_CONVOLUTOR_H
