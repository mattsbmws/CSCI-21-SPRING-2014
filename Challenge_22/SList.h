/*
template class name: SList

private data members:

	head, SLNode<T>* that poTs to the first node in a singly-linked list
	size, unsigned T the count of the number of nodes in the list

public function Terface:

	default constructor, sets values head(NULL) and size(0)
	
	destructor, calls the clear function
	
	void insertHead (T), create a new SLNode and attach as head of list
	void insertTail (T), create a new SLNode and attach at the end of list
	
	void removeHead (), remove the head node from the list
	void removeTail (), remove the tail node from the list
	
	void insert (T), create a new SLNode and insert it in the correct position
	                   in the list so that the values in the nodes are in 
	                   ascending order from head node to tail node
	
	bool removeFirst (T), remove the first appearance of the parameter value;
	                      return true on success or false if the value is not in the list
	
	[NEW] bool removeAll (T), remove all occurrences of the parameter value from the list;
	                      return true on success or false if the value is not in the list
	
	void clear (), clear the entire contents of the list, freeing all memory
	               associated with all nodes
	
	unsigned T getSize () const
	
	string toString () const, return a string representation of the contents
	                          of all nodes in the list, in the format
	                          NUM1,NUM2,...,LASTNUM; return empty string on 
	                          empty list
	                          
*/
#pragma once
#include "SLNode.h"
#include <sstream>
#include <cstdlib>
#include <iostream>
using namespace std;

template <class T>
class SList {
    public:
        SList ()
        :head(NULL), numNodes(0)
        {}
        
        ~SList () {
        	clear();
        }
        
        void insertHead (T value) {
        	SLNode<T>* theNode = new SLNode<T>(value);
        	theNode->setNextNode(head);
        	head = theNode;
        	++numNodes;
        }
        
        void removeHead () {
        	if (head != NULL) {
        		SLNode<T>* temp = head;
        		head = head -> getNextNode();
        		delete temp;
        		--numNodes;
        	}
        }
        
        void insertTail (T contents) {
        	if (head == NULL) {
        		insertHead(contents);
        	}
        	else {
        		SLNode<T>* i = head;
        		SLNode<T>* newNode = new SLNode<T>(contents);
        		
        		while (i->getNextNode() != NULL) {
        			i = i->getNextNode();
        		}
        		i->setNextNode(newNode);
        		++numNodes;
        	}
        }
        
        void removeTail () {
        	if (head != NULL) {
        		SLNode<T>* i = head;
        		SLNode<T>* trailer = NULL;
        		
        		while (i->getNextNode() != NULL) {
        			trailer = i;
        			i = i->getNextNode();
        		}
        		delete i;
        		--numNodes;
        		if (trailer == NULL) {
        			head = NULL;
        		}
        		else {
        			trailer->setNextNode(NULL);
        		}
        	}
        }
        
        void insert (T newContents) {
        	if (head == NULL) {
        		insertHead (newContents);
        	}
        	else if (head->getNextNode() == NULL) {
        		if (newContents < head->getContents()) {
        			insertHead(newContents);
        		}
        		else {	
        			insertTail(newContents);
        		}
        	}
        	else {
        		SLNode<T>* trailer = NULL;
        		SLNode<T>* leader = head;
        		while (leader->getNextNode() != NULL && newContents > leader->getContents()) {
        			trailer = leader;
        			leader = leader->getNextNode();
        		}
        		
        		if (leader->getNextNode() == NULL && newContents > leader->getContents()) {
        			insertTail(newContents);
        		}
        		else {
        			SLNode<T>* theNode = new SLNode<T> (newContents);
        			theNode->setNextNode(leader);
        			if (trailer == NULL) {
        				head = theNode;
        				numNodes++;
        			}
        			else {
        			trailer->setNextNode(theNode);
        			numNodes++;
        			}
        		}
        	}
        }
        
        bool removeFirst (T target) {
        	if (head == NULL)
        		return false;
        	else {
        		SLNode<T>* trailer = NULL;
        		SLNode<T>* leader = head;
        		while (leader != NULL && leader->getContents() != target) {
        			trailer = leader;
        			leader = leader->getNextNode();
        		}
        		if (leader == NULL) {
        			return false;
        		}
        		else if (leader == head) {
        			removeHead();
        			return true;
        		}
        		else {
        			trailer->setNextNode(leader->getNextNode());
        			delete leader;
        			--numNodes;
        			return true;
        		}
        	}
        }
        
        bool removeAll (T target) {
            bool tester(removeFirst(target));
            while (removeFirst(target));
            return tester;
        }
        
        void clear () {
        	while (head != NULL) {
        		removeHead();
        	}
        }
        
        unsigned int getSize () const {
        	return numNodes;
        }
        
        string toString () const {
        	stringstream ss;
        
        	for (SLNode<T>* i = head; i != NULL; i = i -> getNextNode()) {
        		ss << i -> getContents();
        		if (i -> getNextNode() != NULL) {
        			ss << ',';
        		}
        	}
        
        	return ss.str();
        }
    private:
        SLNode<T>* head;
        unsigned int numNodes;
};
