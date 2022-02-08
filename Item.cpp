#include <stdio.h>
#include <string>
#include <vector>
#include "Item.h"


// Item Base class Implementation
vector<Item*> Item::itemColl;
Item::Item()
{
	itemColl.push_back(this);
}
const vector<Item*>& Item::getItemColl()
{
	return itemColl;
}

// Coke Class Implementation
#pragma region Coke
int Coke::quantity;
string Coke::name;
double Coke::price;
Coke gCoke;
Coke::Coke() : Item()
	{

	}
int Coke::getQuantity()
	{
		return quantity;
	}
void Coke::setQuantity(int quantityInput)
	{
		quantity = quantityInput;
	}
string Coke::getName()
	{
		return "COKE";
	}
void Coke::setName(string nameInput)
	{
		name = nameInput;
	}
double Coke::getPrice()
	{
		return price;
	}
void Coke::setPrice(double priceInput)
	{
		price = priceInput;
	}
#pragma endregion

// Biscuits Class Implementation
#pragma region Biscuit
int Biscuit::quantity;
string Biscuit::name;
double Biscuit::price;
Biscuit gBiscuit;
Biscuit::Biscuit() : Item()
{

}
int Biscuit::getQuantity()
{
	return quantity;
}
void Biscuit::setQuantity(int quantityInput)
{
	quantity = quantityInput;
}
string Biscuit::getName()
{
	return "Biscuit";
}
void Biscuit::setName(string nameInput)
{
	name = nameInput;
}
double Biscuit::getPrice()
{
	return price;
}
void Biscuit::setPrice(double priceInput)
{
	price = priceInput;
}
#pragma endregion