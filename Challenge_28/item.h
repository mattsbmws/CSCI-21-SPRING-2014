#pragma once

/* Programming Challenge 28
 * Item Header
 * Matt Lindstrom
 * 05/19/14
 */

#include <iostream>
using namespace std;

class Item {
	public:
		Item(string newName = "item", unsigned int newValue = 0);
		virtual ~Item();
		void setName(string newName);
		void setValue(unsigned int newValue);
		string getName() const;
		unsigned int getValue() const;
		string toString();
	
	private:
		string name;
		unsigned int value;

};
