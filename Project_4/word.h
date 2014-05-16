#pragma once

/*
 * Programming Project 4
 * CSCI21 Programming Project Spring 2014
 * Word Class Header
 *
 * Matthew Lindstrom
 * Date created: 05/05/2014
 * Last date modified: 05/14/2014
 */
 
#include <iostream>
#include <string>
using namespace std;

class Word {
	public:
		Word();
		Word(string newWord);
		virtual ~Word();
		void setWord(string newWord);
		string getWord() const;
		void incrementCount();
		unsigned int getCount() const;
		friend bool operator==(Word left, Word right);
		friend bool operator<(Word left, Word right);
		friend bool operator>(Word left, Word right);
		friend ostream& operator<<(ostream& out, Word theWord);
	private:
		string word;
		unsigned int count;
		
};