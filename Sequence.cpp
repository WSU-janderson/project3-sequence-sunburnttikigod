//Project 3 Sequence - Sequence.cpp
//Charlie Must
//Dr. James Anderson
//CS3100 Data Structures and Algroithms
//Doubly Linked List
//A program for doubly linked node list

#include "Sequence.h"
#include <iostream>
#include <string>
#include <exception>

Sequence::Sequence(size_t sz) : numElts(0), head(nullptr), tail(nullptr) {
    for (size_t i = 0; i < sz; i++) {
        push_back("");
    }
}

Sequence::Sequence(const Sequence &s) : numElts(0), head(nullptr), tail(nullptr) {
    if (!s.empty()) {
        SequenceNode* current = s.head;
        while (current != nullptr) {
            push_back(current->item);
            current = current->next;
        }
    }
}

Sequence::~Sequence() {
    clear();
}

Sequence& Sequence::operator=(const Sequence& s) {
    if (this != &s) {
        clear();
        if (!s.empty()) {
            SequenceNode* current = s.head;
            while (current != nullptr) {
                push_back(current->item);
                current = current->next;
            }
        }
    }
    return *this;
}

std::string& Sequence::operator[](size_t position) const {
    if (position >= this->size()) {
        throw std::exception();
    }
    SequenceNode* current = this->head;
    for (size_t i = 0; i < position; ++i) {
        current = current->next;
    }
    return current->item;
}

void Sequence::push_back(std::string item) {
    SequenceNode* newNode = new SequenceNode(item);
    if (empty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    numElts++;
}

void Sequence::pop_back() {
    if (empty()) {
        throw std::exception();
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        SequenceNode* oldTail = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete oldTail;
    }
    numElts--;
}

void Sequence::insert(size_t position, std::string item) {
    if (position > size()) {
        throw std::exception();
    }
    
    if (position == size()) {
        push_back(item);
        return;
    }
    
    if (position == 0) {
        SequenceNode* newNode = new SequenceNode(item);
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
        numElts++;
        return;
    }
    
    SequenceNode* newNode = new SequenceNode(item);
    SequenceNode* current = head;
    for (size_t i = 0; i < position; i++) {
        current = current->next;
    }
    
    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;
    numElts++;
}

std::string Sequence::front() const {
    if (this->empty()) {
        throw std::exception();
    }
    return head->item;
}

std::string Sequence::back() const {
    if (this->empty()) {
        throw std::exception();
    }
    return tail->item;
}

bool Sequence::empty() const {
    return numElts == 0;
}

size_t Sequence::size() const {
    return numElts;
}

void Sequence::clear() {
    while (!empty()) {
        pop_back();
    }
}

void Sequence::erase(size_t position) {
    if (position >= size()) {
        throw std::exception();
    }
    
    if (position == size() - 1) {
        pop_back();
        return;
    }
    
    if (position == 0) {
        SequenceNode* oldHead = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete oldHead;
        numElts--;
        return;
    }
    
    SequenceNode* current = head;
    for (size_t i = 0; i < position; i++) {
        current = current->next;
    }
    
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    numElts--;
}

void Sequence::erase(size_t position, size_t count) {
    for (size_t i = 0; i < count && position < size(); i++) {
        erase(position);
    }
}

std::ostream &operator<<(std::ostream &os, const Sequence &s) {
    os << "[";
    SequenceNode* current = s.head;
    while (current != nullptr) {
        os << current->item;
        current = current->next;
        if (current != nullptr) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}