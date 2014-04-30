#include "SList.h"

SList::SList ()
:head(NULL), numNodes(0)
{}

SList::~SList () {
	clear();
}

void SList::insertHead (int value) {
	SLNode* theNode = new SLNode(value);
	theNode->setNextNode(head);
	head = theNode;
	++numNodes;
}

void SList::removeHead () {
	if (head != NULL) {
		SLNode* temp = head;
		head = head -> getNextNode();
		delete temp;
		--numNodes;
	}
}

void SList::insertTail (int contents) {
	if (head == NULL) {
		insertHead(contents);
	}
	else {
		SLNode* i = head;
		SLNode* newNode = new SLNode(contents);
		
		while (i->getNextNode() != NULL) {
			i = i->getNextNode();
		}
		i->setNextNode(newNode);
		++numNodes;
	}
}

void SList::removeTail () {
	if (head != NULL) {
		SLNode* i = head;
		SLNode* trailer = NULL;
		
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


void SList::clear () {
	while (head != NULL) {
		removeHead();
	}
}

unsigned int SList::getSize () const {
	return numNodes;
}

string SList::toString () const {
	stringstream ss;

	for (SLNode* i = head; i != NULL; i = i -> getNextNode()) {
		ss << i -> getContents();
		if (i -> getNextNode() != NULL) {
			ss << ',';
		}
	}

	return ss.str();
}
