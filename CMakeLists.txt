cmake_minimum_required(VERSION 3.25)
project(lab1_2)

set(CMAKE_CXX_STANDARD 23)

add_executable(lab1_2 main.cpp
        convolutor/Convolutor.cpp
        convolutor/Convolutor.h
        convolutor/convolutionStrategy/IConvolutionStrategy.h
        reader/Reader.cpp
        reader/Reader.h
        reader/memoryAllocationStrategy/StaticMemoryAllocation.cpp
        reader/memoryAllocationStrategy/StaticMemoryAllocation.h
        reader/memoryAllocationStrategy/IMemoryAllocationStrategy.h
        reader/memoryAllocationStrategy/DynamicMemoryAllocation.cpp
        reader/memoryAllocationStrategy/DynamicMemoryAllocation.h convolutor/convolutionStrategy/sequential/SequentialConvolutor.cpp convolutor/convolutionStrategy/sequential/SequentialConvolutor.h convolutor/convolutionStrategy/parallelOnLines/ParallelOnLinesConvolutor.cpp convolutor/convolutionStrategy/parallelOnLines/ParallelOnLinesConvolutor.h convolutor/convolutionStrategy/parallelOnBlocks/ParallelOnBlocksConvolutor.cpp convolutor/convolutionStrategy/parallelOnBlocks/ParallelOnBlocksConvolutor.h convolutor/convolutionStrategy/parallelHash/ParallelHashConvolutor.cpp convolutor/convolutionStrategy/parallelHash/ParallelHashConvolutor.h)
