/*
 * Programming Project 3
 * CSCI21 Programming Project Spring 2014
 * Main Driver
 *
 * Matthew Lindstrom
 * Date created: 04/16/2014
 * Last date modified: 04/21/2014
 *
 * Unit test code by J. Boyd Trolinger
 */

#include "DLNode.h"
#include "DLList.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main (int argc, char* argv[]) {
	DLList* list;
	char letter;
	string command;
	int data;
	if (argc != 2) {
		cout << "This program requires a text file given as a command line arguement";
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
		ss >> data;		

		switch (letter) {
			case '#': {
				break;
			}
			case 'C': {
				list = new DLList;
				cout << "LIST CREATED" << endl;
				break;
			}
			case 'X': {
				//
				// Grader comments 2014.05.12
				// An 'X' immediately after a 'D', as in the sample
				// file, should result in a 'MUST CREATE LIST INSTANCE'
				// message, because there is no more list. -10 points
				//
				list->clear();
				cout << "LIST CLEARED" << endl;
				break;
			}
			case 'D': {
				delete list;
				cout << "LIST DELETED" << endl;
				break;
			}
			case 'I': {
				list->insert(data);
				cout << "VALUE " << data << " INSERTED" << endl;
				break;
			}	
			case 'F': {
				list->pushFront(data);
				cout << "VALUE " << data << " ADDED TO HEAD" << endl;
				break;
			}
			case 'B': {
				list->pushBack(data);
				cout << "VALUE " << data << " ADDED TO TAIL" << endl;
				break;
			}
			case 'A': {
				try {
					cout << "VALUE " << list->getFront() << " AT HEAD" << endl;
				}
				catch (ListException) {
					cout << "LIST EMPTY" << endl;	
				}
				break;
			}
			case 'Z': {
				try {
					cout << "VALUE " << list->getBack() << " AT TAIL" << endl;
				}
				catch (ListException) {
					cout << "LIST EMPTY" << endl;	
				}
				break;
			}
			case 'T': {
				if (list->getSize() > 0) {
					list->popFront();
					cout << "REMOVED HEAD" << endl;
				}
				else {
					cout << "LIST EMPTY" << endl;
				}
				break;
			}	
			case 'K': {
				if (list->getSize() > 0) {
					list->popBack();
					cout << "REMOVED TAIL" << endl;
				}
				else {
					cout << "LIST EMPTY" << endl;
				}
				break;
			}
			case 'E': {
				if (list->removeAll(data)) {
					cout << "VALUE " << data << " ELIMINATED" << endl;
				} 
				else {	
					cout << "VALUE " << data << " NOT FOUND" << endl;
				}
				break;
			}
			case 'R': {
				if (list->removeFirst(data)) {
					cout << "VALUE " << data << " REMOVED" << endl;
				} 
				else {	
					cout << "VALUE " << data << " NOT FOUND" << endl;
				}
				break;
			}
			case 'G': {
				if (list->get(data)) {
					cout << "VALUE " << data << " FOUND" << endl;
				} 
				else {	
					cout << "VALUE " << data << " NOT FOUND" << endl;
				}
				break;
			}
			case 'N': {
				cout << "LIST SIZE IS " << list->getSize() << endl;
				break;
			}
			case 'P': {
				if (list->getSize() > 0) {
					cout << list->toString() << endl;
				}
				else {
					cout << "LIST EMPTY" << endl;
				}
				break;
			}
			default: {
				cout << "INVALID COMMAND" << endl;
				break;
			}
		}
	}
	return 0;
}

