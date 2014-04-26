#pragma once

/*
 * Programming Project 3
 * CSCI21 Programming Project Spring 2014
 * Doubly-Linked List Header
 *
 * Matthew Lindstrom
 * Date created: 04/16/2014
 * Last date modified: 04/21/2014
 *
 * Unit test code by J. Boyd Trolinger
 */

#include <cstdlib>
#include <sstream>
#include "DLNode.h"
using namespace std;

class DLList {
	public:
		/*
		 * The default constructor.
		 */
		DLList();
		virtual ~DLList();
		void pushFront(int value);
		void popFront();
		int getFront() const;
		void pushBack(int contents);
		void popBack();
		int getBack() const;
		void insert(int newContents);
		bool get(int target);
		bool removeFirst(int target);
		bool removeAll(int target);
		void clear();
		unsigned int getSize() const;
		string toString() const;
	private:
		DLNode* head;
		DLNode* tail;
		unsigned int numNodes;
};

struct ListException {
	ListException(string newMessage = "LIST EMPTY")
	:message(newMessage)
	{}

	string message;
};
