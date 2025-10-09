#ifndef PROJECT3_SEQUENCE_H
#define PROJECT3_SEQUENCE_H

#include <iostream>
#include <memory>
#include <string>

//#include "SequenceNode.h"
#include "SequenceNode.h"

class Sequence {
private:
    SequenceNode *head;
    SequenceNode *tail;
    size_t numElts;

public:
    Sequence(size_t sz = 0);
    Sequence(const Sequence &s);
    ~Sequence();
    Sequence &operator=(const Sequence &s);
    std::string &operator[](size_t position);
    void push_back(std::string item);
    void pop_back();
    void insert(size_t position, std::string item);
    std::string front() const;
    std::string back() const;
    bool empty() const;
    size_t size() const;
    void clear();
    void erase(size_t position);
    void erase(size_t position, size_t count);
    friend std::ostream &operator<<(std::ostream &os, const Sequence &s);
};
#endif //PROJECT3_SEQUENCE_H
