cmake_minimum_required(VERSION 3.26)
project(ASD_Exam_Structures)

set(CMAKE_CXX_STANDARD 17)

add_executable(ASD_Exam_Structures main.cpp
        Structures/LinkedList/LinkedList.cpp
        Structures/LinkedList/LinkedList.h
        Structures/ListVector/ListVector.cpp
        Structures/ListVector/ListVector.h
        Structures/Stack/Stack.cpp
        Structures/Stack/Stack.h
        Structures/Queue/Queue.cpp
        Structures/Queue/Queue.h
        Structures/Dictionary/Dictionary.cpp
        Structures/Dictionary/Dictionary.h
        Structures/TreeNary/TreeNary.cpp
        Structures/TreeNary/TreeNary.h
        Structures/PriorityQueue/PriorityQueue.cpp
        Structures/PriorityQueue/PriorityQueue.h
        Structures/LinkedList/LinearList.cpp
        Structures/LinkedList/LinearList.h
        Structures/Dictionary/HashTable.h
        Structures/BinTree/prof/Bin_treec.h
        Structures/BinTree/prof/Bin_tree.h
        Structures/BinTree/prof/exceptions.h
)
