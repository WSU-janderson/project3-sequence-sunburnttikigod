#ifndef PROJECT3_SEQUENCENODE_H
#define PROJECT3_SEQUENCENODE_H
#include <string>

class SequenceNode {
public:
    std::string item;
    SequenceNode* next;
    SequenceNode* prev;

    SequenceNode(std::string &item) : item(item), next(nullptr), prev(nullptr) {}

    SequenceNode() : next(nullptr), prev(nullptr){};
};
#endif //PROJECT3_SEQUENCENODE_H