#pragma once

/*
 * Programming Project 4
 * CSCI21 Programming Project Spring 2014
 * Binary Search Tree Header
 *
 * Matthew Lindstrom
 * Date created: 05/05/2014
 * Last date modified: 05/14/2014
 */

#include <iostream>
#include "BSTNode.h"
using namespace std;

template <class T>
class BSTree {
	public:
		BSTree()
		:root(NULL), size(0)
		{}

		~BSTree() {
			clear();
		}

		bool insert(T newData) {
			return insert(newData, root);
		}
		
		bool find(T data) {
			return find(data, root);
		}

		bool remove (T data) {
			return remove(data, root);
		}

		void clear() {
			clear(root);
		}

		BSTNode<T>*& get(T data) {
			return get(data, root);
		}
		
		unsigned int getSize() const {
			return size;
		}

		void inOrder() {
			inOrder(root);
		}
		
		void reverseOrder() {
			ReverseOrder(root);
		}
				
	private:
		bool insert(T newData, BSTNode<T>*& tempRoot) {
			if (tempRoot == NULL) {
				tempRoot = new BSTNode<T>(newData);
				++size;
				return true;
			
			} else if (newData < tempRoot -> getContents()) {
				return insert(newData, tempRoot -> getLeftChild());
					
			} else if (newData > tempRoot -> getContents()) {
				return insert(newData, tempRoot -> getRightChild());
			
			} else {
				return false;
			}
		}
		
		bool find(T data, BSTNode<T>*& tempRoot) {
			if (tempRoot == NULL) {
				return false;
				
			} else if (data < tempRoot) {
				return find(data, tempRoot -> getLeftChild());
			
			} else if (data > tempRoot) {
				return find(data, tempRoot -> getRightChild());
			
			} else {
				return true;
			}
		}

		bool remove (T data, BSTNode<T>*& tempRoot) {
			if (tempRoot == NULL) {
				return false;
				
			} else if (data < tempRoot -> getContents()) {
				return remove(data, tempRoot -> getLeftChild());
				
			} else if (data > tempRoot -> getContents()) {
				return remove(data, tempRoot -> getRightChild());
				
			} else {
				if (tempRoot -> getLeftChild() == NULL) {
					BSTNode<T>* oldRoot = tempRoot;
					tempRoot = tempRoot -> getRightChild();
					delete oldRoot;
					oldRoot = NULL;
				} else {
					removeMax(tempRoot -> getContents(), tempRoot -> getLeftChild());   
				}
				--size;
				return true;
			}
		}


		void removeMax (T& data, BSTNode<T>*& tempRoot) {
			if (tempRoot -> getRightChild() == NULL) {
				BSTNode<T>* oldRoot = tempRoot;
				data = tempRoot -> getContents();
				tempRoot = tempRoot -> getLeftChild();
				delete oldRoot;
				oldRoot = NULL;
			} else {
				removeMax (data, tempRoot -> getRightChild());
			}
		}

		void clear(BSTNode<T>*& tempRoot) {
			if (tempRoot != NULL) {
				clear(tempRoot -> getLeftChild());
				clear(tempRoot -> getRightChild());
				delete tempRoot;
				tempRoot = NULL;
				--size;
			}
		}
		
		BSTNode<T>*& get(T data, BSTNode<T>*& tempRoot) {
			if (tempRoot == NULL) {
				return false;
				
			} else if (data < tempRoot) {
				return find(data, tempRoot -> getLeftChild());
			
			} else if (data > tempRoot) {
				return find(data, tempRoot -> getRightChild());
			
			} else {
				return tempRoot;
			}
		}
		
		void inOrder(BSTNode<T>*& tempRoot) {
			if (tempRoot != NULL) {
				inOrder(tempRoot -> getLeftChild());
				cout << (tempRoot -> getContents()) << " ";
				inOrder(tempRoot -> getRightChild());
			}
		}
		
		void reverseOrder(BSTNode<T>*& tempRoot) {
			if (tempRoot != NULL) {
				inOrder(tempRoot -> getRightChild());
				cout << (tempRoot -> getContents()) << " ";
				inOrder(tempRoot -> getLeftChild());
			}
		}
		
		BSTNode<T>* root;
		unsigned int size;
};
