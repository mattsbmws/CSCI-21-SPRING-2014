#include "BSTNode.h"
#include "bstree.h"

/*
 *	Binary Search Tree Definition
 *  Programming Challenge 26
 *  Matt Lindstrom
 */

#include <iostream>
using namespace std;

//public
BSTree::BSTree()
:root(NULL), size(0)
{}

BSTree::~BSTree() {
	clear();
}

bool BSTree::insert(int newNumber) {
	return insert(newNumber, root);
}

void BSTree::clear() {
	clear(root);
}

unsigned int BSTree::getSize() const {
	return size;
}

void BSTree::inOrder() {
	inOrder(root);
}
		
//private
bool BSTree::insert(int newNumber, BSTNode*& tempRoot) {
	if (tempRoot == NULL) {
		tempRoot = new BSTNode(newNumber);
		++size;
		return true;
	
	} else if (newNumber < tempRoot -> getContents()) {
		return insert(newNumber, tempRoot -> getLeftChild());
			
	} else if (newNumber > tempRoot -> getContents()) {
		return insert(newNumber, tempRoot -> getRightChild());
	
	} else {
		return false;
	}
}

void BSTree::clear(BSTNode*& tempRoot) {
	if (tempRoot != NULL) {
		clear(tempRoot -> getLeftChild());
		clear(tempRoot -> getRightChild());
		delete tempRoot;
		tempRoot = NULL;
		--size;
	}
}

void BSTree::inOrder(BSTNode*& tempRoot) {
	if (tempRoot != NULL) {
		inOrder(tempRoot -> getLeftChild());
		cout << (tempRoot -> getContents()) << " ";
		inOrder(tempRoot -> getRightChild());
	}
}

