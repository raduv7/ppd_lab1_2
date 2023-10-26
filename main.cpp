#include <iostream>
#include "reader/Reader.h"
#include "convolutor/Convolutor.h"

using namespace std;

int main(int argc, char **argv) {
    if(argc <= 4) {
        throw runtime_error("invalid number of arguments");
    }

    int fileNumber = stoi(argv[1]),
    threadsCnt = stoi(argv[2]),
    memoryAllocationStrategyCode = stoi(argv[3]),
    convolutionStrategyCode = stoi(argv[4]);

    Reader reader(fileNumber, memoryAllocationStrategyCode);
    Convolutor convolutor(&reader, threadsCnt, convolutionStrategyCode);
    convolutor.convolute();

    return 0;
}
