#include "SLNode.h"

SLNode::SLNode ()
:contents(0), nextNode(NULL)
{}

SLNode::SLNode (int newData)
:contents(newData), nextNode(NULL)
{}

SLNode::~SLNode () {
    nextNode = NULL;
}
void SLNode::setContents (int newContents) {
    contents = newContents;
}
int SLNode::getContents () const {
    return contents;
}
void SLNode::setNextNode (SLNode* newNextNode) {
    nextNode = newNextNode;
}
SLNode* SLNode::getNextNode () const {
    return nextNode;
}
