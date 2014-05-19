/* Programming Challenge 28
 * MagicItem Header
 * Matt Lindstrom
 * 05/19/14
 */

#include <iostream>
using namespace std;
#include "item.h"

class MagicItem : public Item {
	public:
		MagicItem(string newName = "magicitem", unsigned int newValue = 0, string newDescription = "no description", unsigned int newManaRequired = 0);
		virtual ~MagicItem();
		void setDescription(string newDescription);
		void setManaRequired(unsigned int newManaRequired);
		string getDescription() const;
		unsigned int getManaRequired() const;
		string toString();
		
	private:
		string description;
		unsigned int manaRequired;
};
