#include "Item.h"
class User
{
public:
	static int DispatchAndManage(Item* itemToDispatch, int quanityToDispatch)
	{
		try
		{
			if (itemToDispatch == nullptr)
				return -1;
			if (quanityToDispatch > itemToDispatch->getQuantity())
				return -1;

			itemToDispatch->setQuantity(itemToDispatch->getQuantity() - quanityToDispatch);
			return 1;
		}
		catch (exception ex)
		{
			return -1;
		}
	}
};