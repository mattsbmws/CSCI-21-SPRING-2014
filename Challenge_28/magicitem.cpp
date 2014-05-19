/* Programming Challenge 28
 * MagicItem Implementation
 * Matt Lindstrom
 * 05/19/14
 */
 
#include "magicitem.h"
#include <sstream>

MagicItem::MagicItem(string newName, unsigned int newValue, string newDescription, unsigned int newManaRequired)
:Item(newName, newValue), description(newDescription), manaRequired(newManaRequired)
{}

MagicItem::~MagicItem()
{}

void MagicItem::setDescription(string newDescription) {
	description = newDescription;
}

void MagicItem::setManaRequired(unsigned int newManaRequired) {
	manaRequired = newManaRequired;
}

string MagicItem::getDescription() const {
	return description;
}

unsigned int MagicItem::getManaRequired() const {
	return manaRequired;
}

string MagicItem::toString() {
	stringstream ss;
	ss << Item::toString() << ", " << description << ", requires " << manaRequired << " mana";
	return ss.str();
}

