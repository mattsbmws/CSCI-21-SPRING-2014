#pragma once

/*
Define a "header only" template class named Box with:

- one data member -- contents (data type templated)
- overloaded constructor -- one parameter newContents to be assigned to contents
- getter (getContents) and setter (setContents)
- friend overloaded operator<<
*/

#include <iostream>
using namespace std;

template <class T>
class Box {
	public:
		Box ()
		{}
		
		Box (T newContents) 
		:contents(newContents)
		{}
		
		void setContents (T newContents) {
			contents = newContents;
		}
		
		T getContents () const {
			return contents;
		}
		friend ostream& operator << (ostream& outs, Box& source) {
			outs << source.contents;
			return outs;
		}
		
	private:
		T contents;
};