//Project 3 Sequence - Sequence.cpp
//Charlie Must
//CS3100 Data Structures and Algroithms
//Doubly Linked List

#include "SequenceNode.h";
#include <iostream>
#include <string>
#include <exception>

class Sequence {
    size_t numElts;
    SequenceNode *head;
    SequenceNode *tail;

Sequence::Sequence(size_t sz = 0) {
    for (int i = 0; i < sz; i++) {
        push_back("");
    }
}
Sequence::Sequence(const Sequence &s) {
    numElts=0;
    auto* current = new SequenceNode(s.head->item);
    head = current;
    while (current->next != nullptr) {
       push_back(current->item);
        current = current->next;
        numElts++;
    }
}

Sequence::~Sequence() {
    clear();
}
Sequence& Sequence::operator=(const Sequence& s) {
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
    for (size_t i = 0; i < position; ++i) {
        current = current->next;
    }
    return current->item;
}

////This was exhausting, even when I wrote it down and mapped it out all the
////prev and next and back and forths …whew! Counting it as a victory!

void Sequence::push_back(std::string item){
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
    if (position > size()) {
        throw std::exception();
    }
    else {

        SequenceNode* newNode = new SequenceNode(item);
        SequenceNode* current = head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        current->next = newNode;
        numElts++;
    }
}
    std::string Sequence::front() const{
        if (this->empty()) {
            throw std::exception();
            return "Error:Ln102-Sequence";
        }
        else return head->item;
    }
    std::string Sequence::back()const{
        if (this->empty()) {
            throw std::exception();
            return "Error:Ln109-Sequence";
        }
        else return tail->item;
    }
    bool Sequence::empty() const{
        return this->size() == 0;
    }
    size_t Sequence::size() const{
        return numElts;
    }
    void Sequence::clear() {
    while (!empty()) {
        pop_back();
    }
    numElts = 0;
}

    void Sequence::erase(size_t position){

    }

    void Sequence::erase(size_t position, size_t count) {

    }

    friend std::ostream &operator<<(std::ostream &os, const Sequence &s) {
        return os;
    }
};