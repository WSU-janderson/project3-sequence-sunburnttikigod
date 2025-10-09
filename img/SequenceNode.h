//
// Created by sunbu on 10/9/2025.
//

#ifndef SEQUENCE_SEQUENCENODE_H
#define SEQUENCE_SEQUENCENODE_H
class SequenceNode {
public: // to make it easier, we can make the data members public so we don't need
    // getters and setters
    SequenceNode* next; // pointer to next Node. If node is the tail, next is
    // nullptr
    SequenceNode* prev; // pointer to previous Node. If node is the head, prev is
    // nullptr
    std::string item; // the element being stored in the node
    //default constructor, ensure next and prev are nullptr
    SequenceNode() : next(nullptr), prev(nullptr)
    {}
    /// parameterized constructor, next and prev are set to nullptr and the
    /// node's element is set to the given value
    SequenceNode(std::string item) : next(nullptr), prev(nullptr), item(item)
    {}
};
#endif //SEQUENCE_SEQUENCENODE_H