#pragma once

/*
 *	Binary Search Tree Node Header
 *  Programming Challenge 25
 *  Matt Lindstrom
 */

#include <iostream>
using namespace std;

class BSTNode {
	public:
		BSTNode();
		BSTNode(int newContents);
		virtual ~BSTNode();
		
		void setContents (int newContents);
		
		int getContents() const;
		int& getContents();
		
		void setLeftChild(BSTNode* newChild);
		void setRightChild(BSTNode* newChild);
		
		BSTNode* getLeftChild() const;
		BSTNode*& getLeftChild();
		
		BSTNode* getRightChild() const;
		BSTNode*& getRightChild();
		
	private:
		BSTNode* leftChild;
		BSTNode* rightChild;
		int contents;
};