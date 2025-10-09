//
// Created by sunbu on 10/9/2025.
//

#ifndef SEQUENCE_SEQUENCENODE_H
#define SEQUENCE_SEQUENCENODE_H
#include <string>

class SequenceNode {
public:
    SequenceNode *next;
    SequenceNode *prev;
    std::string item;

    SequenceNode() : next(nullptr),
                     prev(nullptr) {
    };

    SequenceNode(const std::string &item) : next(nullptr),
                                              prev(nullptr),
                                              item(item) {
    };
    ~SequenceNode() = default;
    SequenceNode& operator=(const SequenceNode& other);
};
#endif //SEQUENCE_SEQUENCENODE_H
