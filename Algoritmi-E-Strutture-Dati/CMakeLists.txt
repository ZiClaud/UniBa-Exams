cmake_minimum_required(VERSION 3.26)
project(Algoritmi_Lab)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        Algoritmi_Lab
        Strutture/TestStrutture.cpp
        Strutture/GeekLinkedList/GeekLinkedList.cpp
        Strutture/GeekLinkedList/GeekLinkedList.h
        Strutture/Queue/QueueV1.cpp
        Strutture/Queue/QueueV1.h
)
