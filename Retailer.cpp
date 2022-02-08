#include "Item.h"
#include <iostream>
class Retailer
{
public:
	static int ModifyItems(Item* itemToModify, int retailerChoice)
	{
		try
		{
			if (itemToModify == nullptr)
				return -1;
			if (retailerChoice == 1)
			{
				int updatedQuantity = 0;
				cout << "Enter the updated quantity of " << itemToModify->getName() << ": " << endl;
				cin.clear();
				cin >> updatedQuantity;
				if (updatedQuantity >= 0)
					itemToModify->setQuantity(updatedQuantity);
				else
					return -1;
			}
			else if (retailerChoice == 2)
			{
				int updatePrice = 0;
				cout << "Enter the updated Price of " << itemToModify->getName() << ": " << endl;
				cin.clear();
				cin >> updatePrice;
				if (updatePrice > 0)
					itemToModify->setPrice(updatePrice);
				else
					return -1;
			}
			else
				return -1;

			return 1;
		}
		catch (exception ex)
		{
			return -1;
		}
	}
};