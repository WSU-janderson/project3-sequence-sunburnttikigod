// Sequence.h
// Charlie Must
// CS3100 Data Structures and Algorithms
// Dr. James Anderson
// Fall 2025
//
// Declares the Sequence class, a doubly-linked list implementation that supports
// dynamic insertion, deletion, and random access. Each Sequence stores a list of
// string items using SequenceNode objects. This header defines the public interface
// and private data members required for the Sequence class.

#ifndef PROJECT3_SEQUENCE_H
#define PROJECT3_SEQUENCE_H

#include <iostream>
#include <string>
#include "SequenceNode.h"

/**
 * @brief A doubly-linked list of string items.
 * Supports dynamic insertion, deletion, and random access.
 */
class Sequence {
private:
    SequenceNode* head;   ///< Pointer to the first node in the list.
    SequenceNode* tail;   ///< Pointer to the last node in the list.
    size_t numElts;       ///< Number of elements in the sequence.

public:
    /**
     * @brief Constructs a Sequence with `sz` default-initialized elements.
     * @param sz Number of elements to initialize (default is 0).
     */
    Sequence(size_t sz = 0);

    /**
     * @brief Deep copy constructor.
     * @param s Sequence to copy.
     */
    Sequence(const Sequence& s);

    /**
     * @brief Destructor: releases all memory and clears the sequence.
     */
    ~Sequence();

    /**
     * @brief Assignment operator: replaces current contents with a deep copy of `s`.
     * @param s Sequence to assign from.
     * @return Reference to this Sequence.
     */
    Sequence& operator=(const Sequence& s);

    /**
     * @brief Indexing operator.
     * @param position Index to access.
     * @return Reference to item at `position`.
     * @throws std::exception if position is out of bounds.
     */
    std::string& operator[](size_t position) const;

    /**
     * @brief Adds an item to the end of the sequence.
     * @param item The string to append.
     */
    void push_back(std::string item);

    /**
     * @brief Removes the last item from the sequence.
     * @throws std::exception if the sequence is empty.
     */
    void pop_back();

    /**
     * @brief Inserts an item at a specific position.
     * @param position Index to insert at (0 ≤ position ≤ size()).
     * @param item The string to insert.
     * @throws std::exception if position is out of bounds.
     */
    void insert(size_t position, std::string item);

    /**
     * @brief Returns the first item in the sequence.
     * @return The string at the front.
     * @throws std::exception if the sequence is empty.
     */
    std::string front() const;

    /**
     * @brief Returns the last item in the sequence.
     * @return The string at the back.
     * @throws std::exception if the sequence is empty.
     */
    std::string back() const;

    /**
     * @brief Checks if the sequence is empty.
     * @return True if empty, false otherwise.
     */
    bool empty() const;

    /**
     * @brief Returns the number of elements in the sequence.
     * @return The size of the sequence.
     */
    size_t size() const;

    /**
     * @brief Removes all elements from the sequence.
     * @post Sequence becomes empty.
     */
    void clear();

    /**
     * @brief Removes the item at a specific position.
     * @param position Index of item to remove.
     * @throws std::exception if position is out of bounds.
     */
    void erase(size_t position);

    /**
     * @brief Removes a range of items from the sequence.
     * @param position Starting index.
     * @param count Number of items to remove.
     * @throws std::exception if position or count is invalid.
     */
    void erase(size_t position, size_t count);

    /**
     * @brief Outputs the sequence to a stream.
     * @param os Output stream.
     * @param s Sequence to print.
     * @return Reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Sequence& s);
};

#endif //PROJECT3_SEQUENCE_H
