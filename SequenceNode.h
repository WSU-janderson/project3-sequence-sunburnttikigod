#ifndef PROJECT3_SEQUENCENODE_H
#define PROJECT3_SEQUENCENODE_H

#include <string>

/**
 * @brief A node in the doubly-linked Sequence.
 * Stores a string item and pointers to adjacent nodes.
 */
class SequenceNode {
public:
    std::string item;       ///< The data stored in this node.
    SequenceNode* next;     ///< Pointer to the next node (nullptr if tail).
    SequenceNode* prev;     ///< Pointer to the previous node (nullptr if head).

    /**
     * @brief Default constructor.
     * Initializes pointers to nullptr.
     */
    SequenceNode() : item(""), next(nullptr), prev(nullptr) {}

    /**
     * @brief Parameterized constructor.
     * @param item The string to store in the node.
     */
    SequenceNode(const std::string& item) : item(item), next(nullptr), prev(nullptr) {}
};

#endif //PROJECT3_SEQUENCENODE_H
