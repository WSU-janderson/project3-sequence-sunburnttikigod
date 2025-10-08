/**
* SequenceTestHarness.cpp
 * CS 3100
 * Project 3
 *
 * This source file contains the test harness used when grading the Sequence project.
 *
 * For students: DO NOT modify this file. If you cannot get your project to compile, it is not
 * because of this file. Also, modifying this file can give you false-positives or false-negatives
 * when running tests. To run this file in CLion, you need to select SequenceTestHarness from the drop-down
 * menu next to the Build (hammer) icon.
 */

#include <iomanip>
#include <iostream>
#include <string>
#include "Sequence.h"

using namespace std;

// -----------------------------------------------------------------------------
// Change this typedef to switch test type (int, double, std::string, etc.)
// -----------------------------------------------------------------------------
typedef std::string value_type;
// typedef int value_type;
// typedef double value_type;

// -----------------------------------------------------------------------------
// Change this typedef to switch test type (int, double, std::string, etc.)
// -----------------------------------------------------------------------------
typedef std::string value_type;
// typedef int value_type;
// typedef double value_type;

// -----------------------------------------------------------------------------
// Conversion helper to generate values from integer indices.
// -----------------------------------------------------------------------------
inline value_type make_value(int i);

// Overload for string-like types
inline std::string make_value_string(int i) {
	return std::string(1, 'A' + (i % 26));
}

// Generic template fallback for numeric or trivially convertible types
template <typename T>
inline T make_value_generic(int i) {
	return static_cast<T>(i + 1);
}

// Dispatcher
inline value_type make_value(int i) {
	if constexpr (std::is_same_v<value_type, std::string>)
		return make_value_string(i);
	else
		return make_value_generic<value_type>(i);
}

// -----------------------------------------------------------------------------

const std::string evalName{ "" };

// #define __GRADING

#define __CREATE_PRINT
#define __INDEP
#define __PUSH_BACK
#define __PUSH_BACK_EMPTY
#define __POP_BACK
#define __POP_BACK_EMPTY
#define __INSERT
#define __INSERT_INVALID
#define __FRONT
#define __FRONT_EMPTY
#define __BACK
#define __BACK_EMPTY
#define __EMPTY
#define __SIZE
#define __CLEAR
#define __ERASE
#define __ERASE_INVALID
#define __ASSIGNMENT
#define __COPY_CONSTRUCTOR
#define __MEMORY_LEAK_TEST

#define NUM_MEM_TESTS 1000000
#define MEM_TEST_SIZE 10

#ifdef __GRADING
#include <fstream>
#define OUTSTREAM os
#else
#define OUTSTREAM cout
#endif

void testCopyConstructor(Sequence, ostream&);
void memoryLeakTest();

int main() {

#ifdef __GRADING
	ofstream OUTSTREAM;
	OUTSTREAM.open("./evals/" + evalName + "_eval.txt");
	if (!OUTSTREAM.good()) {
		std::cout << "Evaluation failed to open\n";
	}
#endif

	OUTSTREAM << "Grading for " << evalName << "\n";

	// CREATE / PRINT
	try {
		OUTSTREAM << "Testing sequence creation and printing" << endl;
		OUTSTREAM << "--------------------------------------" << endl;
#ifdef __CREATE_PRINT
		Sequence data(4);
		data[0] = make_value(0);
		data[1] = make_value(1);
		data[2] = make_value(2);
		OUTSTREAM << "Sequence:  " << data << endl;
#endif
	}
	catch (exception& e) {
		OUTSTREAM << "Exception: " << e.what() << endl << endl;
	}

	// INDEPENDENT SEQUENCES
	try {
		OUTSTREAM << "Testing multiple sequences" << endl;
		OUTSTREAM << "--------------------------" << endl;
#ifdef __INDEP
		Sequence s1(3);
		Sequence s2(3);

		for (int i = 0; i < 3; i++) {
			s1[i] = make_value(i);
			s2[i] = make_value(100 + i);
		}
		OUTSTREAM << "Sequence1: " << s1 << endl;
		OUTSTREAM << "Sequence2: " << s2 << endl << endl;
#endif
	}
	catch (exception& e) {
		OUTSTREAM << "Exception: " << e.what() << endl << endl;
	}

	// PUSH_BACK
	try {
		OUTSTREAM << "Testing push_back()" << endl;
		OUTSTREAM << "-------------------" << endl;
#ifdef __PUSH_BACK
		Sequence data(3);
		for (int i = 0; i < 3; i++) data[i] = make_value(i);
		data.push_back(make_value(3));
		data.push_back(make_value(4));
		OUTSTREAM << "Sequence:  " << data << endl;
#endif
	}
	catch (exception& e) {
		OUTSTREAM << "Exception: " << e.what() << endl << endl;
	}

	// POP_BACK
	try {
		OUTSTREAM << "Testing pop_back()" << endl;
		OUTSTREAM << "------------------" << endl;
#ifdef __POP_BACK
		Sequence data(5);
		for (int i = 0; i < 5; i++) data[i] = make_value(i);
		data.pop_back();
		data.pop_back();
		OUTSTREAM << "Sequence:   " << data << endl;
#endif
	}
	catch (exception& e) {
		OUTSTREAM << "Exception: " << e.what() << endl << endl;
	}

	// INSERT
	try {
#ifdef __INSERT
		Sequence data(5);
		for (int i = 0; i < 5; i++) data[i] = make_value(i);
		data.insert(3, make_value(99));
		data.insert(0, make_value(88));
		data.insert(6, make_value(77));
		OUTSTREAM << "Sequence:   " << data << endl;
#endif
	}
	catch (exception& e) {
		OUTSTREAM << "Exception: " << e.what() << endl << endl;
	}

	// FRONT / BACK
	try {
#ifdef __FRONT
		Sequence data(3);
		for (int i = 0; i < 3; i++) data[i] = make_value(i);
		OUTSTREAM << "Front: " << data.front() << endl;
#endif
#ifdef __BACK
		Sequence data2(3);
		for (int i = 0; i < 3; i++) data2[i] = make_value(i);
		OUTSTREAM << "Back:  " << data2.back() << endl;
#endif
	}
	catch (exception& e) {
		OUTSTREAM << "Exception: " << e.what() << endl << endl;
	}

	// ERASE
	try {
#ifdef __ERASE
		Sequence data(6);
		for (int i = 0; i < 6; i++) data[i] = make_value(i);
		data.erase(2, 2); // remove two elements
		OUTSTREAM << "Sequence: " << data << endl;
#endif
	}
	catch (exception& e) {
		OUTSTREAM << "Exception: " << e.what() << endl;
	}

	// ASSIGNMENT
	try {
#ifdef __ASSIGNMENT
		Sequence data1(3);
		for (int i = 0; i < 3; i++) data1[i] = make_value(i);
		Sequence data2(0);
		data2 = data1;
		data2[0] = make_value(99);
		OUTSTREAM << "data1: " << data1 << endl;
		OUTSTREAM << "data2: " << data2 << endl;
#endif
	}
	catch (exception& e) {
		OUTSTREAM << "Exception: " << e.what() << endl;
	}

	// COPY CONSTRUCTOR
	try {
#ifdef __COPY_CONSTRUCTOR
		Sequence data(3);
		for (int i = 0; i < 3; i++) data[i] = make_value(i);
		testCopyConstructor(data, OUTSTREAM);
		OUTSTREAM << "Original: " << data << endl;
#endif
	}
	catch (exception& e) {
		OUTSTREAM << "Exception: " << e.what() << endl;
	}

	return 0;
}

void memoryLeakTest() {
	Sequence s(MEM_TEST_SIZE);
	for (int i = 0; i < MEM_TEST_SIZE; i++) {
		s[i] = make_value(i);
	}
}

void testCopyConstructor(Sequence s, ostream& os) {
	s[0] = make_value(99);
	os << "Copied Sequence: " << s << endl;
}
