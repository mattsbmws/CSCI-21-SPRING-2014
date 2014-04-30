/*
Implement the following "header only" template classes including the function Terfaces 
as described below EXACTLY.

##############################################################################################
template class name: SLNode

private data members:

	nextNode, SLNode* that poTs to the next node in a singly-linked list
	contents, T used to store the data contents of this SLNode

public function Terface:

	default constructor, sets values nextNode(NULL) and contents(0)
	overloaded constructor, T parameter assigned to contents
	
	destructor, sets nextNode to NULL
	
	void setContents (T)
	T getContents () const
	
	void setNextNode (SLNode*)
	
	SLNode* getNextNode () const

##############################################################################################
*/
#pragma once

#include <cstdlib>
#include <iostream>
using namespace std;

template <class T>
class SLNode {
    public:
        SLNode ()
        :contents(0), nextNode(NULL)
        {}
        
        SLNode (T newData)
        :contents(newData), nextNode(NULL)
        {}
        
        ~SLNode () {
            nextNode = NULL;
        }
        void setContents (T newContents) {
            contents = newContents;
        }
        T getContents () const {
            return contents;
        }
        void setNextNode (SLNode* newNextNode) {
            nextNode = newNextNode;
        }
        SLNode* getNextNode () const {
            return nextNode;
        }

    private:
        T contents;
        SLNode* nextNode;

};
