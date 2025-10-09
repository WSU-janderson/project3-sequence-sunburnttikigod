//Project 3 Sequence - Sequence.cpp
//Charlie Must
//CS3100 Data Structures and Algroithms
//Doubly Linked List

#include "Sequence.h"
#include <iostream>
#include <string>
#include <exception>
#include <cassert>

Sequence::Sequence(size_t sz) {

}
Sequence::Sequence(const Sequence &s) {

}

Sequence::~Sequence() {
    clear();
}
Sequence &Sequence::operator=(const Sequence &s) {
    return *this;
}
std::string &Sequence::operator[](size_t position) {

}
void Sequence::push_back(std::string item) {

}
void Sequence::pop_back() {

}
void Sequence::insert(size_t position, std::string item) {

}
std::string Sequence::front(){
    return head;
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
    if ( index position is invalid ) {
        throw exception();
    }
    ...
}
