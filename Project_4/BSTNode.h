#pragma once

/*
 * Programming Project 4
 * CSCI21 Programming Project Spring 2014
 * Binary Search Tree Node Header
 *
 * Matthew Lindstrom
 * Date created: 05/05/2014
 * Last date modified: 05/14/2014
 */

#include <iostream>
using namespace std;

template <class T>
class BSTNode {
	public:
		BSTNode() 
		:leftChild(NULL), rightChild(NULL)
		{}

		BSTNode(T newContents) 
		:leftChild(NULL), rightChild(NULL), contents(newContents)
		{}

		~BSTNode() {
			leftChild = rightChild = NULL;
		}

		void setContents (T newContents) {
			contents = newContents;
		}

		T getContents() const {
			return contents;
		}

		T& getContents() {
			return contents;
		}

		void setLeftChild(BSTNode<T>* newChild) {
			leftChild = newChild;
		}

		void setRightChild(BSTNode<T>* newChild) {
			rightChild = newChild;
		}

		BSTNode<T>* getLeftChild() const {
			return leftChild;
		}

		BSTNode<T>*& getLeftChild() {
			return leftChild;
		}

		BSTNode<T>* getRightChild() const {
			return rightChild;
		}

		BSTNode<T>*& getRightChild() {
			return rightChild;
		}
		
	private:
		BSTNode<T>* leftChild;
		BSTNode<T>* rightChild;
		T contents;
};