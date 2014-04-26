#pragma once

/*
 * Programming Project 3
 * CSCI21 Programming Project Spring 2014
 * Doubly-Linked List Node Header
 *
 * Matthew Lindstrom
 * Date created: 04/16/2014
 * Last date modified: 04/21/2014
 *
 * Unit test code by J. Boyd Trolinger
 */
 
#include <cstdlib>
#include <iostream>
using namespace std;

class DLNode {
    public:
        DLNode ();
        DLNode (int newContents);
        virtual ~DLNode ();
        void setContents (int newContents);
        int getContents () const;
	void setNext (DLNode* newNextNode);
        DLNode* getNext () const;
	void setPrevious (DLNode* newPreviousNode);
	DLNode* getPrevious () const;
    private:
        int contents;
        DLNode* nextNode;
	DLNode* previousNode;

};
