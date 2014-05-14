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
	return (left.getWord() == right.getWord());
}

bool operator<(Word left, Word right) {
	return (left.getWord() < right.getWord());
}

bool operator>(Word left, Word right) {
	return (left.getWord() > right.getWord());
}

ostream& operator<<(ostream& out, Word theWord) {
	out << theWord.getWord();
	return out;
}

