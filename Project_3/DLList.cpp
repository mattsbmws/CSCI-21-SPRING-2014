/*
 * Programming Project 3
 * CSCI21 Programming Project Spring 2014
 * Doubly-Linked List Implementation
 *
 * Matthew Lindstrom
 * Date created: 04/16/2014
 * Last date modified: 04/21/2014
 *
 * Unit test code by J. Boyd Trolinger
 */

#include "DLList.h"

DLList::DLList ()
:head(NULL), tail(NULL), numNodes(0)
{}

DLList::~DLList () {
	clear();
}

void DLList::pushFront (int value) {
	DLNode* theNode = new DLNode(value);
	theNode->setNext(head);
	head=theNode;
	++numNodes;

	if(numNodes==1)
		tail = head;
	else
		head->getNext()->setPrevious(head);
}

void DLList::popFront () {
	if (head != NULL && numNodes == 1) {
		head = NULL;
		--numNodes;
	}
	if (head != NULL && numNodes > 1) {
		DLNode* temp = head;
		head = head->getNext();
		delete temp;
		--numNodes;

	//	head->getNext()->setPrevious(head);
		
	}
}

int DLList::getFront () const {
	if (head == NULL) {
		throw ListException();
	}
	else {
		return head->getContents();
	}
}

void DLList::pushBack (int contents) {
	DLNode* theNode = new DLNode(contents);
        theNode->setPrevious(tail);
        tail=theNode;
        ++numNodes;

        if(numNodes==1)
                head = tail;
        else
                tail->getPrevious()->setNext(tail);

}

void DLList::popBack () {
	if (tail != NULL && numNodes == 1) {
		tail = NULL;
		--numNodes;
	}
	if (tail != NULL && numNodes > 1) {
                DLNode* temp = tail;
                tail = tail->getPrevious();
                delete temp;
                --numNodes;
        //        tail->getPrevious()->setNext(tail);
	}
}

int DLList::getBack () const {
	if (head == NULL) {
                throw ListException();
        }   
        else {
                return tail->getContents();
	}
}   


void DLList::insert (int newContents) {
	if(head == NULL || head->getContents() > newContents)
		pushFront(newContents);
    
	DLNode* iterator = head;
	while(iterator !=NULL) {
        	if( iterator->getContents() > newContents) {
   	        	DLNode* temp = iterator->getPrevious();
        	 	DLNode* inserted = new DLNode(newContents);
            
            	 	inserted->setNext(iterator);
            	 	iterator->setPrevious(inserted);

               	 	inserted->setPrevious(temp);
            	 	temp->setNext(inserted);
            
            	 	++numNodes;
                 	return;
		}
		iterator = iterator->getNext();
	}
	pushBack(newContents);
}

	
bool DLList::get(int target) {
	if (head == NULL) {
		return false;
	}
	DLNode* temp = head;
	while (temp != NULL) {
		if (temp->getContents() == target)
			return true;
		temp = temp->getNext();
	}
	return false;
}

bool DLList::removeFirst (int target) {
	if (head == NULL)
		return false;
	else {
		DLNode* iterator = head;
		while (iterator != NULL && iterator->getContents() != target) {
			iterator = iterator->getNext();
		}
		if (iterator == NULL) {
			return false;
		}
		else if (iterator == head) {
			popFront();
			return true;
		}
		else if (iterator == tail) {
			popBack();
			return true;
		}
		else {
			iterator->getPrevious()->setNext(iterator->getNext());
			iterator->getNext()->setPrevious(iterator->getPrevious());
			delete iterator;
			--numNodes;
			return true;
		}
	}
}

bool DLList::removeAll(int target) {
	bool returned(removeFirst(target));
	while (removeFirst(target));
	return returned;
}

void DLList::clear () {
	while (numNodes > 0) {
		popFront();
	}
	head = tail = NULL;
	numNodes = 0;
}

unsigned int DLList::getSize () const {
	return numNodes;
}

string DLList::toString () const {
	stringstream ss;

	for (DLNode* i = head; i != NULL; i = i -> getNext()) {
		ss << i -> getContents();
		if (i -> getNext() != NULL) {
			ss << ',';
		}
	}

	return ss.str();
}

