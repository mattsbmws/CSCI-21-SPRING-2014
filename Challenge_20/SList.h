/*
Declare and implement a class that provides the following interface EXACTLY.

class name: SList

private data members:

	head, SLNode* that points to the first node in a singly-linked list
	size, unsigned int the count of the number of nodes in the list

public function interface:

	default constructor, sets values head(NULL) and size(0)
	
	destructor, calls the clear function
	
	void insertHead (int), create a new SLNode and attach as head of list
	void insertTail (int), create a new SLNode and attach at the end of list
	
	void removeHead (), remove the head node from the list
	void removeTail (), remove the tail node from the list
	
	void insert (int), create a new SLNode and insert it in the correct position
	                   in the list so that the values in the nodes are in 
	                   ascending order from head node to tail node
	
	bool removeFirst (int), remove the first appearance of the parameter value;
	                      return true on success or false if the value is not in the list
	
	void clear (), clear the entire contents of the list, freeing all memory
	               associated with all nodes
	
	unsigned int getSize () const
	
	string toString () const, return a string representation of the contents
	                          of all nodes in the list, in the format
	                          NUM1,NUM2,...,LASTNUM; return empty string on 
	                          empty list
*/

#pragma once

#include <cstdlib>
#include <sstream>
#include "SLNode.h"
using namespace std;

class SList {
	public:
		SList();
		virtual ~SList();
		void insertHead(int value);
		void removeHead();
		void insertTail(int contents);
		void removeTail();
		void insert(int newContents);
		bool removeFirst(int target);
		void clear();
		unsigned int getSize () const;
		string toString () const;
	private:
		SLNode* head;
		unsigned int numNodes;
};
