cmake_minimum_required(VERSION 3.3)
project(LeetCode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(RANGE_SUM_QUERY_2D_IMMUTABLE "src/cpp/Algorithms/304 Range Sum Query 2D - Immutable/main.cpp")
add_executable(RangeSumQuery2D-Immutable ${RANGE_SUM_QUERY_2D_IMMUTABLE})

set(SERIALIZE_AND_DESERIALIZE_BINARY_TREE "src/cpp/Algorithms/297 Serialize and Deserialize Binary Tree/main.cpp")
add_executable(SerializeAndDeserializeBinaryTree ${SERIALIZE_AND_DESERIALIZE_BINARY_TREE})

set(EDGE_OF_BST "src/cpp/Bonus/Edge of BST/main.cpp" "src/cpp/Bonus/Edge of BST/lib/BinaryTree.cpp" "src/cpp/Bonus/Edge of BST/lib/BinaryTree.h" "src/cpp/Bonus/Edge of BST/lib/Bst.cpp" "src/cpp/Bonus/Edge of BST/lib/Bst.h")
add_executable(EdgeOfBst ${EDGE_OF_BST})