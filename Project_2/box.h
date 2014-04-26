#pragma once

/*
 * Programming Project 2
 * CSCI21 Programming Project Spring 2014
 * Box Header
 *
 * Matthew Lindstrom
 * Date created: 03/17/2014
 * Last date modified: 04/11/2014
 *
 * CinReader by J. Boyd Trolinger
 */

#include "prize.h"
#include <iostream>
#include <string>
using namespace std;


class Box {
    public:
        /* 
         * The default constructor.
         * Initializes boxNumber to 0, boxColor to NO COLOR, prizeCapacity to 5,
         * and prizeCount to 0. Prizes array initalized to prizeCapacity.
         */
        Box();
        
        /* 
         * The overloaded constructor.
         * Initializes boxNumber to number, boxColor to color, prizeCapacity to capacity,
         * and prizeCount to 0. Prizes array initalized to prizeCapacity.
         * @param number an unsigned int containing the value for boxNumber.
         * @param color a string containing the color for boxColor.
         * @param capacity an unsigned int containing the value for prizeCapacity.
         */
        Box(unsigned int number, string color, unsigned int capacity);
        
        /*
         * The destructor.
         */
        ~Box();
        
        /*
         * Sets boxNumber to the value passed in.
         * @param newNumber an unsigned int containing the new value for boxNumber.
         */
        void setBoxNumber(unsigned int newNumber);
        
        /*
         * Retrieves the current number of a box.
         * @return the unsigned int value stored in boxNumber.
         */
        unsigned int getBoxNumber() const;
        
        /*
         * Sets boxColor to the value passed in.
         * @param newColor a string containing the new value for boxColor.
         */
        void setBoxColor(string newColor);
        
        /*
         * Retrieves the current color of a box.
         * @return the string stored in boxColor.
         */
        string getBoxColor() const;
        
        /*
         * Retrieves the current prize capacity of a box.
         * @return the unsigned int value stored in prizeCaoacity.
         */
        unsigned int getPrizeCapacity() const;
        
        /*
         * Retrieves the current number of prizes stored in a box.
         * @return the unsigned int value stored in prizeCount.
         */
        unsigned int getPrizeCount() const;
        
        /*
         * Adds a prize to the prizes array.
         * @param newPrize the new prize that is to be added to prizes.
         * @return true if there is enough space in the array and the prize is added, else false.
         */
        bool addPrize(Prize newPrize);
        
        /*
         * Retrieves the prize a given index location.
         * @param index the unsigned int passed in for the location in the array.
         * @return the Prize by reference if the index is valid, else return scratch.
         */
        Prize& getPrize(unsigned int index);
        
        /*
         * Removes a prize from the prizes array.
         * @param index the unsigned int passed in for the location in the array.
         * @return the removed Prize if the index is valid, else return scratch.
         */
        Prize removePrize(unsigned int index);
        
    
    private:
        unsigned int boxNumber;
        string boxColor;
        unsigned int prizeCapacity;
        unsigned int prizeCount;
        Prize scratch;
        Prize* prizes;
};
