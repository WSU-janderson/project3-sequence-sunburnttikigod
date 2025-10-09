//
// Created by sunbu on 10/9/2025.
//
#include <string>
#include <utility>

class SequenceNode {
    SequenceNode *next;
    SequenceNode *prev;
    std::string item;

    SequenceNode() : next(nullptr),
                     prev(nullptr) {
    }

    SequenceNode(const std::string &item) : next(nullptr),
                                     prev(nullptr),
                                     item(item) {
    }
    ~SequenceNode() {}

    SequenceNode& operator=(const SequenceNode& other) {
        if (this != &other) {
            this->item = other.item;
        }
        return *this;
    }
};
