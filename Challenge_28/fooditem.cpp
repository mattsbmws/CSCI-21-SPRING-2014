/* Programming Challenge 28
 * FoodItem Implementation
 * Matt Lindstrom
 * 05/19/14
 */
 
#include "fooditem.h"
#include <sstream>
#include <iomanip>

FoodItem::FoodItem(string newName, unsigned int newValue, unsigned int newCalories, string newUnitOfMeasure, float newUnits)
:Item(newName, newValue), calories(newCalories), unitOfMeasure(newUnitOfMeasure), units(newUnits)
{}

FoodItem::~FoodItem()
{}

void FoodItem::setCalories(unsigned int newCalories) {
	calories = newCalories;
}

void FoodItem::setUnitOfMeasure(string newUnitofMeasure) {
	unitOfMeasure = newUnitofMeasure;
}

void FoodItem::setUnits(float newUnits) {
	units = newUnits;
}

unsigned int FoodItem::getCalories() const {
	return calories;
}

string FoodItem::getUnitOfMeasure() const {
	return unitOfMeasure;
}

float FoodItem::getUnits() const {
	return units;
}

string FoodItem::toString() {
	stringstream ss;
	ss.setf(ios::showpoint | ios::fixed);
	ss.precision(2);
	
	ss << Item::toString() << ", " << units << " " << unitOfMeasure << ", " << calories << " calories";
	return ss.str();
}

