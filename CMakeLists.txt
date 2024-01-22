cmake_minimum_required(VERSION 3.26)
project(ASD_Exam_Structures)

set(CMAKE_CXX_STANDARD 17)

add_executable(ASD_Exam_Structures
        main.cpp
        Structures/LinkedList/LinkedList.h
        Structures/ListVector/ListVector.h
        Structures/Stack/Stack.h
        Structures/Queue/Queue.h
        Structures/Dictionary/Dictionary.h
        Structures/TreeList/TreeList.h
        Structures/PriorityQueue/PriorityQueue.h
        Structures/LinkedList/LinearList.h
        Structures/Dictionary/HashTable.h
        Structures/BinTree/Bin_treec.h
        Structures/BinTree/Bin_tree.h
        Structures/BinTree/exceptions.h
        Structures/TreeList/Tree.h
)
