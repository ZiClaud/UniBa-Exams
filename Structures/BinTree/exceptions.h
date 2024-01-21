//
// Created by ziclaud on 21/01/24.
//

#ifndef ASD_EXAM_STRUCTURES_EXCEPTIONS_H
#define ASD_EXAM_STRUCTURES_EXCEPTIONS_H

#include <stdexcept>

struct NullNode : public std::invalid_argument {
    NullNode() : invalid_argument("Parametro nodo nullo.") {};
};

struct FullSize : public std::invalid_argument {
    FullSize() : invalid_argument("Dimensione massima raggiunta.") {};
};

struct RootExists : public std::domain_error {
    RootExists() : domain_error(
            "Radice giÃ  presente.") {};
};

struct EmptyTree : public std::domain_error {
    EmptyTree() : domain_error(
            "Albero vuoto.") {};
};

struct NodeExists : public std::domain_error {
    NodeExists() : domain_error(
            "Nodo giÃ  presente.") {};
};

#endif //ASD_EXAM_STRUCTURES_EXCEPTIONS_H
