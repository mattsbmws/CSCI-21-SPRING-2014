#pragma once

/*
 *	Binary Search Tree Header
 *  Programming Challenge 26
 *  Matt Lindstrom
 */

//bool remove (int), return value returned by private function remove(int, root)

//[NEW] bool remove (int, BSTNode*&), traverse the tree and remove the node containing the target 
//	               integer if present, return true; return false if target integer is not in tree
	
//	[NEW] void removeMax (int&, BSTNode*&), helper function for private remove

#include <iostream>
#include "BSTNode.h"
using namespace std;

class BSTree {
	public:
		BSTree();
		virtual ~BSTree();
		bool insert(int newNumber);
		bool remove (int number);
		void clear();
		unsigned int getSize() const;
		void inOrder();
		
	private:
		bool insert(int newNumber, BSTNode*& tempRoot);
		bool remove (int number, BSTNode*& tempRoot);
		void removeMax (int& number, BSTNode*& tempRoot);
		void clear(BSTNode*& tempRoot);
		void inOrder(BSTNode*& tempRoot);
		BSTNode* root;
		unsigned int size;
};