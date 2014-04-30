/*
 * Programming Project 2
 * CSCI21 Programming Project Spring 2014
 * Main Driver
 *
 * Matthew Lindstrom
 * Date created: 03/17/2014
 * Last date modified: 04/11/2014
 *
 * CinReader by J. Boyd Trolinger
 * Unit test code by J. Boyd Trolinger
 */

#include "box.h"
#include "prize.h"
#include "CinReader.h"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest ();

/*
 * Holds the program until the user presses enter.
 */
void stall();
void clear();

int main (int, char*[]) {
	bool keepGoing(true);
	
	do {
        CinReader reader;
        clear();
        
        cout << "\nWelcome to Programming Project 2!\n\n";
            
        cout << "\n1. Run the non-interactive unit test\n"
	        "2. Create a box with standard options\n"
	        "3. Create a box with custom options\n"
	        "4. Exit the program\n\n"
	        "\nWhat would you like to do? ";

	    switch(reader.readInt(1, 19)) {
	        case 1: {
	            unittest();
	            stall();
	            clear();
	            break;
	        }
	        case 2: {
	            bool boxMenu(true);
	            Box defaultBox;
	            cout << "\nBox created with default options.\n";
	            stall();
	            clear();
	            
	            while (boxMenu) {
	                clear();
	                cout << "\nBox Test Menu\n\n"
	                        "Current box number is " << 
	                        defaultBox.getBoxNumber() << 
	                        " in " << defaultBox.getBoxColor() << " with " <<
	                        defaultBox.getPrizeCount() << 
	                        " prizes filled out of " << 
	                        defaultBox.getPrizeCapacity() << endl;
	                
	                cout << "\n1. Change the box number\n"
	                         "2. Change the box color\n"
	                         "3. Add a prize\n"
	                         "4. Remove a prize\n"
	                         "5. Check prizes\n"
	                         "6. Go back\n"
	                         
	                         "\nWhat would you like to do? ";
	                         
	                         
    	            switch (reader.readInt(1,6)) {
	                    case 1: {
	                        cout << "\nWhat would you like the number to be? ";
	                        defaultBox.setBoxNumber(reader.readInt());
	                        break;
	                    }
	                    
    	                case 2: {
    	                    cout << "\nWhat would you like the color to be? ";
	                        defaultBox.setBoxColor(reader.readString());
	                        break;
	                    }
	                    
	                    case 3: {
	                       // unsigned int currentFreeLocation(0);
	                        if (defaultBox.getPrizeCount() < defaultBox.getPrizeCapacity()) {
	                          //  currentFreeLocation = (defaultBox.getPrizeCount() + 1);
	                        
	                        cout << "\nWould you like to add the default prize (y for default, n for custom)? ";
	                            switch (toupper(reader.readChar("YyNn"))) {
	                                case 'N': { 
	                                    unsigned int newPrizeValue(0);
	                                    string newPrizeName("NO NAME");
	                                
	                                    cout << "\nWhat should the name of the prize be? ";
	                                    newPrizeName = reader.readString();
	                                
	                                    cout << "\nWhat should the value of the prize be? ";
	                                    newPrizeValue = reader.readInt();
	                                
	                                    Prize customPrize(newPrizeName, newPrizeValue);
	                                    if (defaultBox.addPrize(customPrize)) {
                                            cout << "\nCreated custom prize in next available slot.\n";
                                            stall();
                                            clear();
                                            break;
	                                    }
	                                    else {
	                                        cout << "\nCouldn't create prize.\n";
	                                        stall();
	                                        clear();
	                                        break;
	                                    }
                                        
                                        break;
	                            }
	                                case 'Y': {
	                                    Prize defaultPrize;
	                                    if (defaultBox.addPrize(defaultPrize)) {
	                                        cout << "\nCreated default prize in next available slot.\n";
	                                        stall();
	                                        clear();
	                                        break;
	                                    }
	                                    else {
	                                        cout << "\nCouldn't create prize.\n";
	                                        stall();
	                                        clear();
	                                        break;
	                                    }
	                                }
	                            }
	                        }
	                        else {
	                            cout << "\nThe box is full to capacity\n";
	                            stall();
	                            clear();
	                        }
    	                    break;
	                    }
	                    
	                    case 4: {
	                        if (defaultBox.getPrizeCount() > 0) {
	                        cout << "You cannot remove default prizes.\n"
	                                "\nWhat prize would you like to remove (starting at 1)? ";
	                            defaultBox.removePrize(reader.readInt() - 1);
	                            break;
	                        }
	                        else {
	                            cout << "\nThere are no prizes to remove;\n";
	                            stall();
	                            break;
	                        }
    	                }
	                    
	                    case 5: {
	                        cout << "\n\nThere are currently " << defaultBox.getPrizeCount() << " prizes.\n";
	                        stall();
	                        if (defaultBox.getPrizeCount() > 0) {
	                            for (unsigned int i(0); i < defaultBox.getPrizeCount(); ++i) {
	                                cout << "\nPrize " << (i + 1) << " is named " << defaultBox.getPrize(i).getPrizeName() <<
	                                " and has the value " << defaultBox.getPrize(i).getPrizeValue() << endl;
	                            }
	                            stall();
	                            
	                            unsigned int selection1(0);
	                            unsigned int selection2(0);
	                            
	                            cout << "What is the first prize you would you like to check? ";
	                            selection1 = (reader.readInt() - 1);
	                            cout << "What is the second prize you would you like to check? ";
	                            selection2 = (reader.readInt() - 1);
	                            
	                            if (defaultBox.getPrize(selection1) == defaultBox.getPrize(selection2)) {
	                                cout << "Yep, they are the same.\n";
	                                stall();
	                            }
	                            else {
	                                cout << "Nope, they are different.\n";
	                                stall();
	                            }
	                        }
	                        break;
    	                }
    	                
	                    case 6: {
	                        boxMenu = false;
	                        break;
	                    }
	                }
	            }
	            break;
	        }
	        case 3: {
	     	    bool boxMenu(true);
	     	    unsigned int numberChoice(0);
	     	    string colorChoice("NO COLOR");
	     	    unsigned int capacityChoice(0);
	     	    
	     	    cout << "\nCustom box setup\n\n"
	     	            "\nWhat would you like to number the box? ";
	     	    numberChoice = reader.readInt();
	     	    
	     	    cout << "\nWhat color would you like it? ";
	     	    
	     	    colorChoice = reader.readString();
	     	    
	     	    cout << "\nHow many prizes should it hold? ";
	     	    
	     	    capacityChoice = reader.readInt();
	     	    
	     	    Box customBox(numberChoice, colorChoice, capacityChoice);
	            cout << "\nBox created with custom options.\n";
	            stall();
	            clear();
	            
	            while (boxMenu) {
	                clear();
	                cout << "\nBox Test Menu\n\n"
	                        "Current box number is " << 
	                        customBox.getBoxNumber() << 
	                        " in " << customBox.getBoxColor() << " with " <<
	                        customBox.getPrizeCount() << 
	                        " prizes filled out of " << 
	                        customBox.getPrizeCapacity() << endl;
	                
	                cout << "\n1. Change the box number\n"
	                         "2. Change the box color\n"
	                         "3. Add a prize\n"
	                         "4. Remove a prize\n"
	                         "5. Check prizes\n"
	                         "6. Go back\n"
	                         
	                         "\nWhat would you like to do? ";
	                         
	                         
    	            switch (reader.readInt(1,6)) {
	                    case 1: {
	                        cout << "\nWhat would you like the number to be? ";
	                        customBox.setBoxNumber(reader.readInt());
	                        clear();
	                        break;
	                    }
	                    
    	                case 2: {
    	                    cout << "\nWhat would you like the color to be? ";
	                        customBox.setBoxColor(reader.readString());
	                        clear();
	                        break;
	                    }
	                    
	                    case 3: { 
	                       // unsigned int currentFreeLocation(0);
	                        if (customBox.getPrizeCount() < customBox.getPrizeCapacity()) {
	                           // currentFreeLocation = (customBox.getPrizeCount() + 1);
	                        
	                        cout << "\nWould you like to add the default prize (y for default, n for custom)? ";
	                            switch (toupper(reader.readChar("YyNn"))) {
	                                case 'N': { 
	                                    unsigned int newPrizeValue(0);
	                                    string newPrizeName("NO NAME");
	                                
	                                    cout << "\nWhat should the name of the prize be? ";
	                                    newPrizeName = reader.readString();
	                                
	                                    cout << "\nWhat should the value of the prize be? ";
	                                    newPrizeValue = reader.readInt();
	                                
	                                    Prize customPrize(newPrizeName, newPrizeValue);
	                                    if (customBox.addPrize(customPrize)) {
                                            cout << "\nCreated custom prize in next available slot.\n";
                                            stall();
                                            clear();
                                            break;
	                                    }
	                                    else {
	                                        cout << "\nCouldn't create prize.\n";
	                                        stall();
	                                        clear();
	                                        break;
	                                    }
                                        
                                        break;
	                            }
	                                case 'Y': {
	                                    Prize defaultPrize;
	                                    if (customBox.addPrize(defaultPrize)) {
	                                        cout << "\nCreated default prize in next available slot.\n";
	                                        stall();
	                                        clear();
	                                        break;
	                                    }
	                                    else {
	                                        cout << "\nCouldn't create prize.\n";
	                                        stall();
	                                        clear();
	                                        break;
	                                    }
	                                }
	                            }
	                        }
	                        else {
	                            cout << "\nThe box is full to capacity\n";
	                            stall();
	                            clear();
	                        }
    	                    break;
	                    }
	                    
	                    case 4: {
	                        if (customBox.getPrizeCount() > 0) {
	                        cout << "You cannot remove default prizes.\n"
	                                "\nWhat prize would you like to remove (starting at 1)? ";
	                            customBox.removePrize(reader.readInt() - 1);
	                            break;
	                        }
	                        else {
	                            cout << "\nThere are no prizes to remove;\n";
	                            stall();
	                            break;
	                        }
    	                }
	                    
	                    case 5: {
	                        cout << "\n\nThere are currently " << customBox.getPrizeCount() << " prizes.\n";
	                        stall();
	                        
	                        if (customBox.getPrizeCount() > 0) {
	                            for (unsigned int i(0); i < customBox.getPrizeCount(); ++i) {
	                                cout << "\nPrize " << (i + 1) << " is named " << customBox.getPrize(i).getPrizeName() <<
	                                " and has the value " << customBox.getPrize(i).getPrizeValue() << endl;
	                            }
	                            stall();
	                            
	                            unsigned int selection1(0);
	                            unsigned int selection2(0);
	                            
	                            cout << "What is the first prize you would you like to check? ";
	                            selection1 = (reader.readInt() - 1);
	                            cout << "What is the second prize you would you like to check? ";
	                            selection2 = (reader.readInt() - 1);
	                            
	                            if (customBox.getPrize(selection1) == customBox.getPrize(selection2)) {
	                                cout << "Yep, they are the same.\n";
	                                stall();
	                            }
	                            else {
	                                cout << "Nope, they are different.\n";
	                                stall();
	                            }
	                        }
	                        break;
	                    }
	                    case 6: {
	                        boxMenu = false;
	                        break;
	                    }
	                }
	            }
	            break;
	        }
	        case 4: {
	            clear();
	            keepGoing = false;
	            break;
	        }
	    }
	}
	while (keepGoing);
	
    return 0;
}

void stall() {
    CinReader reader;
    cout << "(press enter to continue): ";
    string lag(reader.readString(true));
}

void clear() {
    for (int i(0); i < 75; ++i) {
        cout << "\n";    
    }
}

/*
 * Unit testing functionb1. Do not alter.
 */

void unittest ()
{
    cout << "\nSTARTING UNIT TEST\n\n";
	
    Box b1;
    Box b2(42, "blue", 3);
	
    cout << "** TESTING DEFAULT BOX **\n\n";
	
    try {
        btassert<bool>(b1.getBoxNumber() == 0);
        cout << "Passed TEST 1: Box getBoxNumber()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 1 Box getBoxNumber() #\n";
    }
	
    try {
        btassert<bool>(b1.getBoxColor() == "NO COLOR");
        cout << "Passed TEST 2: Box getBoxColor()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 2 Box getBoxColor() #\n";
    }
    
    try {
        btassert<bool>(b1.getPrizeCapacity() == 5);
        cout << "Passed TEST 3: Box getPrizeCapacity()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 3 Box getPrizeCapacity() #\n";
    }
	
    try {
        btassert<bool>(b1.getPrizeCount() == 0);
        cout << "Passed TEST 4: Box getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 4 Box getPrizeCount() #\n";
    }
	
    b1.setBoxNumber(99);
    try {
        btassert<bool>(b1.getBoxNumber() == 99);
        cout << "Passed TEST 5: Box setBoxNumber()/getBoxNumber()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 5 Box setBoxNumber()/getBoxNumber() #\n";
    }
	
    b1.setBoxColor("red");
    try {
        btassert<bool>(b1.getBoxColor() == "red");
        cout << "Passed TEST 6: Box setBoxColor()/getBoxColor()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 6 Box setBoxColor()/getBoxColor() #\n";
    }
    
    cout << "\n** TESTING CUSTOM BOX **\n\n";
	
    try {
        btassert<bool>(b2.getBoxNumber() == 42);
        cout << "Passed TEST 7: Box getBoxNumber()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 7 Box getBoxNumber() #\n";
    }
	
    try {
        btassert<bool>(b2.getBoxColor() == "blue");
        cout << "Passed TEST 8: Box getBoxColor()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 8 Box getBoxColor() #\n";
    }
    
    try {
        btassert<bool>(b2.getPrizeCapacity() == 3);
        cout << "Passed TEST 9: Box getPrizeCapacity()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 9 Box getPrizeCapacity() #\n";
    }
	
    try {
        btassert<bool>(b2.getPrizeCount() == 0);
        cout << "Passed TEST 10: Box getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 10 Box getPrizeCount() #\n";
    }
	
    try {
        btassert<bool>(b2.getPrize(0) == Prize());
        cout << "Passed TEST 11: Box getPrize(0)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 11 Box getPrize(0) #\n";
    }
	
    try {
        btassert<bool>(b2.removePrize(0) == Prize());
        cout << "Passed TEST 12: Box removePrize(0)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 12 Box removePrize(0) #\n";
    }
    
    b2.addPrize(Prize("BRONZE PRIZE", 1));
    try {
        btassert<bool>(b2.getPrizeCount() == 1);
        cout << "Passed TEST 13: Box addPrize()/getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 13 Box addPrize()/getPrizeCount() #\n";
    }
    
    b2.addPrize(Prize("SILVER PRIZE", 100));
    try {
        btassert<bool>(b2.getPrizeCount() == 2);
        cout << "Passed TEST 14: Box addPrize()/getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 14 Box addPrize()/getPrizeCount() #\n";
    }
        
    b2.addPrize(Prize("GOLD PRIZE", 1000));
    try {
        btassert<bool>(b2.getPrizeCount() == 3);
        cout << "Passed TEST 15: Box addPrize()/getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 15 Box addPrize()/getPrizeCount() #\n";
    }
    
    try {
        btassert<bool>(b2.addPrize(Prize("DIAMOND PRIZE", 999)) == false);
        cout << "Passed TEST 16: Box addPrize(ARRAY FULL)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 16 Box addPrize(ARRAY FULL) #\n";
    }
	
    try {
        btassert<bool>(b2.getPrize(1) == Prize("SILVER PRIZE", 100));
        cout << "Passed TEST 17: Box getPrize(1)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 17 Box getPrize(1) #\n";
    }
	
    try {
        btassert<bool>(b2.removePrize(2) == Prize("GOLD PRIZE", 1000));
        cout << "Passed TEST 18: Box removePrize(2)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 18 Box removePrize(2) #\n";
    }
    
    try {
        btassert<bool>(b2.getPrizeCount() == 2);
        cout << "Passed TEST 19: Box getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 19 Box getPrizeCount() #\n";
    }
	
    try {
        btassert<bool>(b2.removePrize(2) == Prize());
        cout << "Passed TEST 20: Box removeCargo(2)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 20 Box removeCargo(2) #\n";
    }
	
    try {
        btassert<bool>(b2.getPrize(2) == Prize());
        cout << "Passed TEST 21: Box getPrize(2)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 21 Box getPrize(2) #\n";
    }
	
    try {
        btassert<bool>(b2.addPrize(Prize("RUBY PRIZE", 9999)) == true);
        cout << "Passed TEST 22: Box addPrize(\"RUBY PRIZE\", 9999)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 22 Box addPrize(\"RUBY PRIZE\", 9999) #\n";
    }
    
    try {
        btassert<bool>(b2.getPrizeCount() == 3);
        cout << "Passed TEST 23: Box getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 23 Box getPrizeCount() #\n";
    }
	
    try {
        btassert<bool>(b2.getPrizeCapacity() == 3);
        cout << "Passed TEST 24: Box getPrizeCapacity()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 24 Box getPrizeCapacity() #\n";
    }
	
    cout << "\n** TESTING PRIZE **\n\n";
	
    Prize p1;
	
    try {
        btassert<bool>(p1.getPrizeName() == "NO NAME");
        cout << "Passed TEST 25: Prize getPrizeName()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 25 Prize getPrizeName() #\n";
    }
	
    try {
        btassert<bool>(p1.getPrizeValue() == 0);
        cout << "Passed TEST 26: Prize getPrizeValue()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 26 Prize getPrizeValue() #\n";
    }
	
    p1.setPrizeName("FOOD PRIZE");
    try {
        btassert<bool>(p1.getPrizeName() == "FOOD PRIZE");
        cout << "Passed TEST 27: Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 27 Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName() #\n";
    }
	
    p1.setPrizeValue(17);
    try {
        btassert<bool>(p1.getPrizeValue() == 17);
        cout << "Passed TEST 28: Prize setPrizeValue(17)/getPrizeValue()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 28 Prize setPrizeValue(17)/getPrizeValue() #\n";
    }
	
    Prize p2("HAT PRIZE", 50);
	
    try {
        btassert<bool>(p2.getPrizeName() == "HAT PRIZE");
        cout << "Passed TEST 29: Prize getPrizeName()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 29 Prize getPrizeName() #\n";
    }
	
    try {
        btassert<bool>(p2.getPrizeValue() == 50);
        cout << "Passed TEST 30: Prize getPrizeValue()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 30 Prize getPrizeValue() #\n";
    }
    
    try {
        btassert<bool>(!(p1 == p2));
        cout << "Passed TEST 31: !(Prize == Prize)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 31 !(Prize == Prize) #\n";
    }
    
    p2.setPrizeName("FOOD PRIZE");
    try {
        btassert<bool>(p2.getPrizeName() == "FOOD PRIZE");
        cout << "Passed TEST 32: Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 32 Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName() #\n";
    }
	
    p2.setPrizeValue(17);
    try {
        btassert<bool>(p2.getPrizeValue() == 17);
        cout << "Passed TEST 33: Prize setPrizeValue(17)/getPrizeValue()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 33 Prize setPrizeValue(17)/getPrizeValue() #\n";
    }
    
    try {
        btassert<bool>(p1 == p2);
        cout << "Passed TEST 34: (Prize == Prize)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 34 (Prize == Prize) #\n";
    }
    
    p2.setPrizeValue(1);
    try {
        btassert<bool>(!(p1 == p2));
        cout << "Passed TEST 35: !(Prize == Prize)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 35 !(Prize == Prize) #\n";
    }
	
    cout << "\nUNIT TEST COMPLETE\n\n";
}

template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
        throw X();
}
