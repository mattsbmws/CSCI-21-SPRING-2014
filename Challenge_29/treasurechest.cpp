#include "treasurechest.h"

void TreasureChest::addItem (const Item& newItem) {
     chest.push_back(newItem);    
}

void TreasureChest::insertItem (const Item& newItem, unsigned int position) {
     if (position > chest.size() - 1) {
          chest.push_back(newItem);
     
     } else {
          vector<Item>::iterator it(chest.begin() + position);
          chest.insert(it,newItem); 
     }
}

const Item* TreasureChest::getItem (unsigned int position) {
     if (chest.empty() || position > chest.size() - 1) {
          return NULL;
     
     } else {
          return &chest[position];
     }
}

Item TreasureChest::removeItem (unsigned int position) throw (string) {
     if (chest.empty() || position > chest.size() - 1) {
          throw string("ERROR: attempting remove at invalid position");

     } else {
          Item erasedItem = chest[position];
          vector<Item>::iterator it(chest.begin() + position);
          chest.erase(it);
          return erasedItem;
     }
}

void TreasureChest::clear () {
     if (!chest.empty()) { 
          chest.clear();
     }
}

bool TreasureChest::empty () const {
     if (chest.empty()) {
          return true;
     
     } else {
          return false;
     }
}

unsigned int TreasureChest::getSize () const {
     return chest.size();    
}

void TreasureChest::sortByName () {
    sort(chest.begin(), chest.end(), compareItemsByName);
}

void TreasureChest::sortByValue () {
    sort(chest.begin(), chest.end(), compareItemsByValue);
}

void TreasureChest::sortByQuantity () {
    sort(chest.begin(), chest.end(), compareItemsByQuantity);
    
}

ostream& operator<< (ostream& outs, const TreasureChest& src) {
     if (src.chest.empty()) {
          outs << "";
          return outs;
     }

     vector<Item>::const_iterator it(src.chest.begin());
     
     if (it == src.chest.end()) {
          outs << *it;
     }

     while (it != src.chest.end() - 1) {
          outs << *it << ",";
          ++it;
     }
     outs << *it;
     return outs;
}

bool compareItemsByName (const Item& lsrc, const Item& rsrc) {
     if (lsrc.name < rsrc.name) {
          return true;

     } else {
          return false;
     }    
}

bool compareItemsByValue (const Item& lsrc, const Item& rsrc) {
     if (lsrc.value < rsrc.value) {
          return true;

     } else {
          return false;
     }    
}

bool compareItemsByQuantity (const Item& lsrc, const Item& rsrc) {
     if (lsrc.quantity < rsrc.quantity) {
          return true;

     } else {
          return false;
     }    
}

