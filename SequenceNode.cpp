// SequenceNode.cpp
// Charlie Must
// CS3100 Data Structures and Algorithms
// Dr. James Anderson
// Fall 2025
//
// Implements the SequenceNode class used in the doubly-linked Sequence structure.
// Each node stores a string item and pointers to adjacent nodes.
// This file defines the constructors for node initialization.
#include <string>

class SequenceNode {
    SequenceNode *next;
    SequenceNode *prev;
    std::string item;
    /**
     * @brief Default constructor.
     * Initializes item to empty string and pointers to nullptr.
     */
    SequenceNode() : next(nullptr),
                     prev(nullptr) {
    }
    /**
     * @brief Parameterized constructor.
     * @param item The string to store in the node.
     * Initializes pointers to nullptr.
     */
    SequenceNode(const std::string &item) : next(nullptr),
                                     prev(nullptr),
                                     item(item) {
    }
};
