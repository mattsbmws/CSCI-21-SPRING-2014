#pragma once

/*
 * Programming Project 3
 * CSCI21 Programming Project Spring 2014
 * Doubly-Linked List Node Header
 *
 * Matthew Lindstrom
 * Date created: 04/16/2014
 * Last date modified: 04/30/2014
 */

#include <cstdlib>
#include <iostream>
using namespace std;

class DLNode {
    public:
		/*
		 * The default constructor.
		 * Initializes nextNode to NULL, previousNode to NULL, and contents to 0.
		 */
        DLNode ();
		/*
		 * The overloaded constructor. Takes newContents and creates a node with that value.
		 * Initializes nextNode to NULL, previousNode to NULL, and contents to newContents.
		 */
        DLNode (int newContents);
		/*
		 * The destructor.
		 */
        virtual ~DLNode ();
		/*
		 * Sets contents to newContents.
		 * @param newContents an int containing the new value for contents.
		 */
        void setContents (int newContents);
		/*
		 * Returns contents.
		 * @return an int containing the contents.
		 */
        int getContents () const;
		/*
		 * Sets nextNode to a pointer for the newNextNode.
		 * @param newNextNode a DLNode* pointer to set the nextNode location.
		 */
		void setNext (DLNode* newNextNode);
		/*
		 * Returns the current pointer for nextNode.
		 * @return a DLNode* pointer to the current nextNode location.
		 */
		DLNode* getNext () const;
		/*
		 * Sets previousNode to a pointer for the newPreviousNode.
		 * @param newPreviousNode a DLNode* pointer to set the previousNode location.
		 */
		void setPrevious (DLNode* newPreviousNode);
		/*
		 * Returns the current pointer for previousNode.
		 * @return a DLNode* pointer to the current previousNode location.
		 */
		DLNode* getPrevious () const;
    private:
        int contents;
        DLNode* nextNode;
	DLNode* previousNode;

};
