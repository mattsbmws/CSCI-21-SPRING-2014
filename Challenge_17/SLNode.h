#pragma once

#include <cassert>
#include <cstdlib>
#include <iostream>
using namespace std;

/*
Declare and implement a class that provides the following interface EXACTLY.

class name: SLNode

private data members:

	nextNode, SLNode* that points to the next node in a singly-linked list
	contents, int used to store the data contents of this SLNode

public function interface:

	default constructor, sets values nextNode(NULL) and contents(0)
	overloaded constructor, int parameter assigned to contents
	
	destructor, sets nextNode to NULL
	
	void setContents (int)
	int getContents () const
	
	void setNextNode (SLNode*)
	
	SLNode* getNextNode () const
*/

class SLNode {
    public:
        SLNode ();
        SLNode (int newData);
        virtual ~SLNode ();
        void setContents (int newContents);
        int getContents () const;
        void setNextNode (SLNode* newNextNode);
        SLNode* getNextNode () const;
    private:
        int contents;
        SLNode* nextNode;

};
