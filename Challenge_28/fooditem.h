/* Programming Challenge 28
 * FoodItem Header
 * Matt Lindstrom
 * 05/19/14
 */

#include <iostream>
using namespace std;
#include "item.h"

class FoodItem : public Item {
	public:
		FoodItem(string newName = "fooditem", unsigned int newValue = 0, unsigned int newCalories = 0, string newUnitOfMeasure = "nounits", float newUnits = 0);
		virtual ~FoodItem();
		void setCalories(unsigned int newCalories);
		void setUnitOfMeasure(string newUnitofMeasure);
		void setUnits(float newUnits);
		unsigned int getCalories() const;
		string getUnitOfMeasure() const;
		float getUnits() const;
		string toString();
		
	private:
		unsigned int calories;
		string unitOfMeasure;
		float units;
};

