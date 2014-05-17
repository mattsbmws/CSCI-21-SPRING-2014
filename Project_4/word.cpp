/*
 * Programming Project 4
 * CSCI21 Programming Project Spring 2014
 * Word Class Implementation
 *
 * Matthew Lindstrom
 * Date created: 05/05/2014
 * Last date modified: 05/14/2014
 */
#include "word.h"
 
#include <iostream>
#include <string>
using namespace std;

Word::Word()
:count(1)
{}

Word::Word(string newWord)
:word(newWord), count(1)
{}

Word::~Word() 
{}

void Word::setWord(string newWord) {
	word = newWord;
}

string Word::getWord() const {
	return word;
}

void Word::incrementCount() {
	++count;
}

unsigned int Word::getCount() const {
	return count;
}

bool operator==(Word left, Word right) {
	for(unsigned int i(0); i < left.getWord().length(); ++i) {
		left.word[i] = toupper(left.getWord()[i]);
	}
	for(unsigned int j(0); j < right.getWord().length(); ++j) {
       		right.word[j] = toupper(right.getWord()[j]);
	}
	return (left.getWord() == right.getWord());
}

bool operator<(Word left, Word right) {
	for(unsigned int i(0); i < left.getWord().length(); ++i) {
		left.word[i] = toupper(left.getWord()[i]);
	}
	for(unsigned int j(0); j < right.getWord().length(); ++j) {
       		right.word[j] = toupper(right.getWord()[j]);
	}
	return (left.getWord() < right.getWord());
}

bool operator>(Word left, Word right) {
	for(unsigned int i(0); i < left.getWord().length(); ++i) {
		left.word[i] = toupper(left.getWord()[i]);
	}
	for(unsigned int j(0); j < right.getWord().length(); ++j) {
       		right.word[j] = toupper(right.getWord()[j]);
	}
	return (left.getWord() > right.getWord());
}

ostream& operator<<(ostream& out, Word wordIn) {
	out << wordIn.getWord() << " " << wordIn.getCount();
	return out;
}

