#include <iostream>
#include "reader/Reader.h"
#include "convolutor/Convolutor.h"
#include <chrono>

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

    // Get the current time at the start
    auto startTime = std::chrono::high_resolution_clock::now();

    // Place your code to be timed here (e.g., convolutor.convolute())
    convolutor.convolute();

    // Get the current time at the end
    auto endTime = std::chrono::high_resolution_clock::now();

    // Calculate the elapsed time in milliseconds
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    // Convert to a long (if needed)
    long elapsedTimeMs = static_cast<long>(elapsedTime.count());

    std::cout << elapsedTimeMs;

    return 0;
}
