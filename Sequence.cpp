//Project 3 Sequence - Sequence.cpp
//Charlie Must
//CS3100 Data Structures and Algroithms
//Doubly Linked List

#include "Sequence.h"
#include <iostream>
#include <string>
#include <exception>
#include <cassert>

#include "img/SequenceNode.h"

Sequence::Sequence(size_t sz = 0) {
    for (int i = 0; i < sz; i++) {
        push_back("");
    }
}
Sequence::Sequence(const Sequence &s) {
    auto* current = new SequenceNode(s.head->item);
    head = current;
    while (current->next != nullptr) {
       push_back(current->item);
        current = current->next;
    }
}

Sequence::~Sequence() {
    clear();
}
Sequence &Sequence::operator=(const Sequence &s) {
    if (s.empty()) {
        clear();
    }
    else {

        SequenceNode* current = s.head;
        head->next = current;
        for (int i = 0; i < s.numElts; i++) {
            SequenceNode* newNode = new SequenceNode(current->item);
            newNode->next = current->next;
            current = current->next;
        }
    }

}
std::string& Sequence::operator[](size_t position) {
    if (position < 0 || position >= this->size()) {
        throw std::exception();
    }
    auto* current =  this->head;
    for (int i = 0; i < position-1; i++) {
        current = current->next;
    }
    return current->item;
}
////This was exhausting, even when i wrote it down and mapped it out all the
////prev and next and back and forths ....whew! Counting it as a victory!

void Sequence::push_back(std::string item) {
    auto* newNode = new SequenceNode(item);
    if (empty()) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
void Sequence::pop_back() {
    if (!empty()) {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
}
void Sequence::insert(size_t position, std::string item) {
    if (position > sz) {
        throw std::exception();
    }
    SequenceNode* current = new SequenceNode(item);
    for (int i = 0; i < position-1; i++) {
    }
    N->prev = A;
        N->next = B;
        B->prev = N;

}
std::string Sequence::front(){
    if (this->empty()) {

    }
    return ;
}
std::string Sequence::back(){
    return tail;
}
bool Sequence::empty() const {
    return size() == 0;
}
size_t Sequence::size() const {
    return sz;
}
void Sequence::clear() {

}
void Sequence::erase(size_t position) {


}
void Sequence::erase(size_t position, size_t count) {

}
friend std::ostream &operator<<(std::ostream &os, const Sequence &s) {
    return os;
}
Sequence::value_type& Sequence::operator[]( index_type position )
{
    if (position < 0 || position >= this->size()) {
        throw std::exception();
    }
}
Sequence