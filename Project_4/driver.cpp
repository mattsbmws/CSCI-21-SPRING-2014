//
// Grader comments 2014.05.21
// -10 points total
//
/*
 * Programming Project 4
 * CSCI21 Programming Project Spring 2014
 * Binary Search Tree Driver
 *
 * Matthew Lindstrom
 * Date created: 05/05/2014
 * Last date modified: 05/14/2014
 */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cctype>

#include "BSTNode.h"
#include "bstree.h"
#include "word.h"
using namespace std;

int main (int argc, char* argv[]) {
	BSTree<Word>* tree = NULL;

	char letter;
	string command;
	string theString;

	if (argc != 2) {
		cout << "This program requires a text file given as a command line arguement" << endl;
		return 1;
	}

	ifstream fin(argv[1]);
	if (!fin.good()) {
		cout << "Opening file failed";
		return 1;
	}

	while (getline(fin, command)) {
		letter = command[0];
		command = command.substr(1);
		stringstream ss(command);
		ss >> theString;
		switch (letter) {
			case '#': {
				break;
			}

			case 'C': {
				if (tree == NULL) {
					tree = new BSTree<Word>;
					cout << "TREE CREATED" << endl;
					break;

				} else {
					delete tree;
					tree = NULL;
					tree = new BSTree<Word>;
					cout << "TREE CREATED" << endl;
					break;
				}
			}

			case 'X': {
				if (tree == NULL) {
					cout << "MUST CREATE TREE INSTANCE" << endl;
					break;

				} else {
					tree -> clear();
					cout << "TREE CLEARED" << endl;
					break;
				}
			}

			case 'D': {
				if (tree == NULL) {
					cout << "MUST CREATE TREE INSTANCE" << endl;
					break;

				} else {
					delete tree;
					tree = NULL;
					cout << "TREE DELETED" << endl;
					break;
				}
			}

			case 'I': {
				if (tree == NULL) {
					cout << "MUST CREATE TREE INSTANCE" << endl;
					
				} else {
					if (tree -> insert(theString)) {
						cout << "WORD " << theString << " INSERTED" << endl;

					} else {
						cout << "WORD " << theString << " INCREMENTED" << endl;
						tree -> get(theString) -> incrementCount();
					}	
				}
				break;
			}
	
			case 'F': {
				if (tree == NULL) {
					cout << "MUST CREATE TREE INSTANCE" << endl;
					break;

				} else if (tree -> getSize() == 0) {
					cout << "TREE EMPTY" << endl;
				
				} else {
					if (tree -> find(theString)) {
						cout << "FOUND " << theString << endl;
						break;

					} else {	
						cout << theString << " NOT FOUND" << endl;
						break;
					}
				}
			}

			case 'R': {
				if (tree == NULL) {
					cout << "MUST CREATE TREE INSTANCE" << endl;
					break;

				} else if (tree -> getSize() == 0) {
					cout << "TREE EMPTY" << endl;
					
					//
					// Grader comments 2014.05.21
					// Missing 'break' here; program falls through to
					// the 'G' case.
					// -5 points
					break;	// Rob

				} else {
					if (tree -> remove(theString)) {
						cout << theString << " REMOVED" << endl;
						break;

					} else {	
						cout << theString << " NOT FOUND" << endl;
						break;
					}
				}
			}	
			
			case 'G': {
				if (tree == NULL) {
					cout << "MUST CREATE TREE INSTANCE" << endl;
					break;

				} else if (tree -> getSize() == 0) {
					cout << "TREE EMPTY" << endl;
					
					//
					// Grader comments 2014.05.21
					// Missing 'break' here; program falls through to
					// the 'N' case.
					// -5 points
					break;	// Rob

				} else {
					if (tree -> get(theString) == NULL) {
						cout << theString << " NOT FOUND" << endl;
						break;

					} else {	
						cout << "GOT " << *tree -> get(theString) << endl;
						break;
					}
				}
			}
			
			case 'N': {
				if (tree == NULL) {
					cout << "MUST CREATE TREE INSTANCE" << endl;
					break;

				} else {
					cout << "TREE SIZE IS " << tree -> getSize() << endl;
					break;
				}
			}

			case 'O': {
				if (tree == NULL) {
					cout << "MUST CREATE TREE INSTANCE" << endl;
					break;

				} else {
					if (tree -> getSize() == 0) {
						cout << "TREE EMPTY" << endl;
						break;

					} else {
						tree -> inOrder();
						break;
					}
				}
			}

			case 'E': {
				if (tree == NULL) {
					cout << "MUST CREATE TREE INSTANCE" << endl;
					break;

				} else {
					if (tree -> getSize() == 0) {
						cout << "TREE EMPTY" << endl;
						break;

					} else {
						tree -> reverseOrder();
						break;
					}
				}
			}
			default: {
				break;
			}
		}
	}
	return 0;
}
