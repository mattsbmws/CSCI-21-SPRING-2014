/*
 * Programming Project 3
 * CSCI21 Programming Project Spring 2014
 * Doubly-Linked List Node Implementation
 *
 * Matthew Lindstrom
 * Date created: 04/16/2014
 * Last date modified: 04/30/2014
 */

#include "DLNode.h"

DLNode::DLNode ()
:contents(0), nextNode(NULL), previousNode(NULL)
{}

DLNode::DLNode (int newContents)
:contents(newContents), nextNode(NULL), previousNode(NULL)
{}

DLNode::~DLNode () 
{}

void DLNode::setContents (int newContents) {
    contents = newContents;
}

int DLNode::getContents () const {
    return contents;
}

void DLNode::setNext (DLNode* newNextNode) {
    nextNode = newNextNode;
}

DLNode* DLNode::getNext () const {
    return nextNode;
}

void DLNode::setPrevious (DLNode* newPreviousNode) {
    previousNode = newPreviousNode;
}

DLNode* DLNode::getPrevious () const {
    return previousNode;
}

