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
		SLNode* leader = head;
		while (leader->getNextNode() != NULL && newContents > leader->getContents()) {
			trailer = leader;
			leader = leader->getNextNode();
		}
		
		if (leader->getNextNode() == NULL && newContents > leader->getContents()) {
			insertTail(newContents);
		}
		else {
			SLNode* theNode = new SLNode (newContents);
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

bool SList::removeFirst (int target) {
	if (head == NULL)
		return false;
	else {
		SLNode* trailer = NULL;
		SLNode* leader = head;
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
