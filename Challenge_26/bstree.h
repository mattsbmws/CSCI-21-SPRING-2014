#pragma once

/*
 *	Binary Search Tree Header
 *  Programming Challenge 26
 *  Matt Lindstrom
 */

#include <iostream>
#include "BSTNode.h"
using namespace std;

class BSTree {
	public:
		BSTree();
		virtual ~BSTree();
		bool insert(int newNumber);
		void clear();
		unsigned int getSize() const;
		void inOrder();
		
	private:
		bool insert(int newNumber, BSTNode*& tempRoot);
		void clear(BSTNode*& tempRoot);
		void inOrder(BSTNode*& tempRoot);
		BSTNode* root;
		unsigned int size;
};