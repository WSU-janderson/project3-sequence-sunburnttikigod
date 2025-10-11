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

/**
 * @brief Constructs a Sequence with `sz` default-initialized elements.
 * @param sz Number of elements to initialize.
 * @post Sequence contains `sz` empty strings.
 */
Sequence::Sequence(size_t sz) : numElts(0), head(nullptr), tail(nullptr) {
    for (size_t i = 0; i < sz; i++) {
        push_back("");
    }
}

/**
 * @brief Deep copy constructor.
 * @param s Sequence to copy.
 * @post Creates a new Sequence with the same elements as `s`.
 */
Sequence::Sequence(const Sequence &s) : numElts(0), head(nullptr), tail(nullptr) {
    if (!s.empty()) {
        SequenceNode* current = s.head;
        while (current != nullptr) {
            push_back(current->item);
            current = current->next;
        }
    }
}

/**
 * @brief Destructor: clears all nodes to free memory.
 */
Sequence::~Sequence() {
    clear();
}

/**
 * @brief Assignment operator: deep copies from `s`.
 * @param s Sequence to assign from.
 * @return Reference to this Sequence.
 */
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

/**
 * @brief Indexing operator.
 * @param position Index to access.
 * @return Reference to item at `position`.
 * @throws std::exception if position is out of bounds.
 */
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

/**
 * @brief Adds a new item to the end of the sequence.
 * @param item The string to append.
 * @post Sequence size increases by one.
 */
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

/**
 * @brief Removes the last item from the sequence.
 * @throws std::exception if the sequence is empty.
 * @post Sequence size decreases by one.
 */
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

/**
 * @brief Inserts an item at a specific position.
 * @param position Index to insert at (0 ≤ position ≤ size()).
 * @param item The string to insert.
 * @throws std::exception if position is out of bounds.
 * @post Sequence size increases by one.
 */
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

/**
 * @brief Returns the first item in the sequence.
 * @return The string at the front.
 * @throws std::exception if the sequence is empty.
 */
std::string Sequence::front() const {
    if (this->empty()) {
        throw std::exception();
    }
    return head->item;
}

/**
 * @brief Returns the last item in the sequence.
 * @return The string at the back.
 * @throws std::exception if the sequence is empty.
 */
std::string Sequence::back() const {
    if (this->empty()) {
        throw std::exception();
    }
    return tail->item;
}

/**
 * @brief Checks if the sequence is empty.
 * @return True if empty, false otherwise.
 */
bool Sequence::empty() const {
    return numElts == 0;
}

/**
 * @brief Returns the number of elements in the sequence.
 * @return The size of the sequence.
 */
size_t Sequence::size() const {
    return numElts;
}

/**
 * @brief Removes all elements from the sequence.
 * @post Sequence becomes empty.
 */
void Sequence::clear() {
    while (!empty()) {
        pop_back();
    }
}

/**
 * @brief Removes the item at a specific position.
 * @param position Index of item to remove.
 * @throws std::exception if position is out of bounds.
 * @post Sequence size decreases by one.
 */
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

/**
 * @brief Removes a range of items from the sequence.
 * @param position Starting index.
 * @param count Number of items to remove.
 * @throws std::exception if position or count is invalid.
 * @post Sequence size decreases by up to `count`.
 */
void Sequence::erase(size_t position, size_t count) {
    for (size_t i = 0; i < count && position < size(); i++) {
        erase(position);
    }
}

/**
 * @brief Outputs the sequence to a stream.
 * @param os Output stream.
 * @param s Sequence to print.
 * @return Reference to the output stream.
 */
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
