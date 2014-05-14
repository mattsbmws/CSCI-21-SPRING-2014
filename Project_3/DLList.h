#pragma once

/*
 * Programming Project 3
 * CSCI21 Programming Project Spring 2014
 * Doubly-Linked List Header
 *
 * Matthew Lindstrom
 * Date created: 04/16/2014
 * Last date modified: 04/30/2014
 */

#include <cstdlib>
#include <sstream>
#include "DLNode.h"
using namespace std;

class DLList {
	public:
		/*
		 * The default constructor.
		 * Initializes head to NULL, tail to NULL, and numNodes 0.
		 */
		DLList();
		/*
		 * The destructor - also calls clear().
		 */
		virtual ~DLList();
		/*
		 * Adds a value to the front of the list.
		 * @param value an int containing the value for the new node.
		 */
		void pushFront(int value);
		/*
		 * Removes a value from the front of the list.
		 */
		void popFront();
		/*
		 * Returns the value of the node that head is pointing to.
		 * @return the int value stored in what head is pointing to.
		 */
		int getFront() const;
		/*
		 * Adds a value to the back of the list.
		 * @param contents an int containing the value for the new node.
		 */
		void pushBack(int contents);
		/*
		 * Removes a value from the back of the list.
		 */
		void popBack();
		/*
		 * Returns the value of the node that tail is pointing to.
		 * @return the int value stored in what tail is pointing to.
		 */
		int getBack() const;
		/*
		 * Inserts a value into the list according to ascending numerical order.
		 * @param newContents an int containing the value for the new node.
		 */
		void insert(int newContents);
		/*
		 * Locates a value in the list.
		 * @param target an int containing the value to be searched for.
		 * @return true if value exists in list and is removed, false if not.
		 */
		bool get(int target) const;
		/*
		 * Removes the first instance of a value in the list.
		 * @param target an int containing the value to be searched for.
		 * @return true if value exists in list and is removed, false if not.
		 */
		bool removeFirst(int target);
		/*
		 * Removes the all instances of a value in the list.
		 * @param target an int containing the value to be searched for.
		 * @return true if value exists in list and is removed, false if not.
		 */
		bool removeAll(int target);
		/*
		 * Clears the list by calling popFront until the list is empty.
		 * Sets head and tail to NULL, numNodes to 0.
		 */
		void clear();
		/*
		 * Returns the size of the list.
		 * @return unsigned int containing the number of nodes currently stored.
		 */
		unsigned int getSize() const;
		/*
		 * Indexes the list and stores all values into a string, comma separated.
		 * @return a string containing all values, comma separated.
		 */
		string toString() const;
	private:
		DLNode* head;
		DLNode* tail;
		unsigned int numNodes;

		//
		// Grader comments 2014.05.14
		// toString() creates the right string but doesn't send it to the output.
		// -10 points 
		//
		friend std::ostream& operator<<(std::ostream& out, DLList const& inList) {
			out << inList.toString();
			return out;
		}
};

struct ListException {
	ListException(string newMessage = "LIST EMPTY")
	:message(newMessage)
	{}

	string message;
};
