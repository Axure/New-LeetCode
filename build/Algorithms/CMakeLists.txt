
set(Boost_USE_STAITIC ON)
find_package(Boost)

set(RANGE_SUM_QUERY_2D_IMMUTABLE "../../src/cpp/Algorithms/304 Range Sum Query 2D - Immutable/main.cpp")
add_executable(RangeSumQuery2D-Immutable ${RANGE_SUM_QUERY_2D_IMMUTABLE})

set(SERIALIZE_AND_DESERIALIZE_BINARY_TREE "../../src/cpp/Algorithms/297 Serialize and Deserialize Binary Tree/main.cpp")
add_executable(SerializeAndDeserializeBinaryTree ${SERIALIZE_AND_DESERIALIZE_BINARY_TREE})

set(EDGE_OF_BST
        "../../src/cpp/Bonus/Edge of BST/lib/BinaryTree.cpp"
        "../../src/cpp/Bonus/Edge of BST/lib/BinaryTree.h"
        "../../src/cpp/Bonus/Edge of BST/lib/Bst.cpp"
        "../../src/cpp/Bonus/Edge of BST/lib/Bst.h")
set(EDGE_OF_BST_TEST
        "../../src/cpp/Bonus/Edge of BST/test/main.cpp"
        "../../src/cpp/Utilities/Logger.cpp"
        "../../src/cpp/Utilities/Logger.h")
set(EDGE_OF_BST_MAIN
        "../../src/cpp/Bonus/Edge of BST/main.cpp" 
        "../../src/cpp/Utilities/Logger.cpp"
        "../../src/cpp/Utilities/Logger.h")
add_executable(EdgeOfBst
        ${EDGE_OF_BST}
        ${EDGE_OF_BST_MAIN})
add_executable(EdgeOfBstTest
        ${EDGE_OF_BST}
        ${EDGE_OF_BST_TEST})


add_executable(CREATE_MAXIMUM_NUMBER
        "../../src/cpp/Algorithms/321 Create Maximum Number/main.cpp"
        "../../src/cpp/Algorithms/321 Create Maximum Number/GreatNumber.cpp"
        "../../src/cpp/Algorithms/321 Create Maximum Number/GreatNumber.h")
add_executable(CREATE_MAXIMUM_NUMBER_ONE_DIMENSIONAL
        "../../src/cpp/Algorithms/321 Create Maximum Number/one_dimensional.cpp"
        "../../src/cpp/Algorithms/321 Create Maximum Number/GreatNumber.cpp"
        "../../src/cpp/Algorithms/321 Create Maximum Number/GreatNumber.h")

add_executable(91_Decode_Ways
        "../../src/cpp/Algorithms/91 Decode Ways/test.cpp"
        "../../src/cpp/Algorithms/91 Decode Ways/solution.hpp")

add_executable(328_Odd_Even_Linked_List
        "../../src/cpp/Algorithms/328 Odd Even Linked List/solution.hpp"
        "../../src/cpp/Algorithms/328 Odd Even Linked List/main.cpp")

add_executable(330_Patching_Array
        "../../src/cpp/Algorithms/330. Patching Array/main.cpp"
        "../../src/cpp/Algorithms/330. Patching Array/Solution.hpp")
