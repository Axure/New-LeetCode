cmake_minimum_required(VERSION 3.0)
project(LeetCode)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(Boost_USE_STAITIC ON)
find_package(Boost)

set(RANGE_SUM_QUERY_2D_IMMUTABLE "src/cpp/Algorithms/304 Range Sum Query 2D - Immutable/main.cpp")
add_executable(RangeSumQuery2D-Immutable ${RANGE_SUM_QUERY_2D_IMMUTABLE})

set(SERIALIZE_AND_DESERIALIZE_BINARY_TREE "src/cpp/Algorithms/297 Serialize and Deserialize Binary Tree/main.cpp")
add_executable(SerializeAndDeserializeBinaryTree ${SERIALIZE_AND_DESERIALIZE_BINARY_TREE})

set(EDGE_OF_BST "src/cpp/Bonus/Edge of BST/lib/BinaryTree.cpp" "src/cpp/Bonus/Edge of BST/lib/BinaryTree.h" "src/cpp/Bonus/Edge of BST/lib/Bst.cpp" "src/cpp/Bonus/Edge of BST/lib/Bst.h")
set(EDGE_OF_BST_TEST "src/cpp/Bonus/Edge of BST/test/main.cpp" src/cpp/Utilities/Logger.cpp src/cpp/Utilities/Logger.h)
set(EDGE_OF_BST_MAIN "src/cpp/Bonus/Edge of BST/main.cpp" src/cpp/Utilities/Logger.cpp src/cpp/Utilities/Logger.h)
add_executable(EdgeOfBst ${EDGE_OF_BST} ${EDGE_OF_BST_MAIN})
add_executable(EdgeOfBstTest ${EDGE_OF_BST} ${EDGE_OF_BST_TEST})

add_subdirectory(build)