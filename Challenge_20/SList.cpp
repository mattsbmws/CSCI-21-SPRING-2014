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

void SList::insert (int newContents) {
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
		SLNode* trailer = NULL;
		SLNode* spot = head;
		while (spot->getNextNode() != NULL && newContents > spot->getContents()) {
			trailer = spot;
			spot = spot->getNextNode();
		}
		
		if (spot->getNextNode() == NULL && newContents > spot->getContents()) {
			insertTail(newContents);
		}
		else {
			SLNode* nodee = new SLNode (newContents);
			nodee->setNextNode(spot);
			if (trailer == NULL) {
				head = nodee;
				numNodes++;
			}
			else {
			trailer->setNextNode(nodee);
			numNodes++;
			}
		}
	}
}

bool SList::removeFirst (int target) {
	if (head == NULL)
		return false;
	else {
		SLNode* trailer = NULL;
		SLNode* spot = head;
		while (spot != NULL && spot->getContents() != target) {
			trailer = spot;
			spot = spot->getNextNode();
		}
		if (spot == NULL) {
			return false;
		}
		else if (spot == head) {
			removeHead();
			return true;
		}
		else {
			trailer->setNextNode(spot->getNextNode());
			delete spot;
			--numNodes;
			return true;
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
