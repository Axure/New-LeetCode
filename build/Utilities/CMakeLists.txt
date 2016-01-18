add_library(Logger
        ../../src/cpp/Utilities/Logger.cpp
        ../../src/cpp/Utilities/Logger.h)


add_executable(ReversedIndexedArrayTest
        ../../src/cpp/Utilities/DataStructures/ReversedIndexedArrayTest.cpp
        ../../src/cpp/Utilities/DataStructures/ReverseIndexedArray.hpp)
target_link_libraries(ReversedIndexedArrayTest Logger)