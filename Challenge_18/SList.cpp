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
