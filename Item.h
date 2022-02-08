#pragma once
#include <vector>
#include<string>
using namespace std;

class Item
{
public:
    static vector<Item*> itemColl;	
public:
	virtual string getName() = 0;
	virtual void setName(string nameInput) = 0;
	virtual double getPrice() = 0;
	virtual void setPrice(double priceInput) = 0;
	virtual int getQuantity() = 0;
	virtual void setQuantity(int quantityInput) = 0;

protected:
    Item();

public:
    static const vector<Item*>& getItemColl();
};
class Coke : public Item
{
public:
	static int quantity;
	static string name;
	static double price;

	string getName();
	void setName(string nameInput);
	double getPrice();
	void setPrice(double priceInput);
	int getQuantity();
	void setQuantity(int quantityInput);
	Coke();
};
class Biscuit : public Item
{
public:
	static int quantity;
	static string name;
	static double price;

	string getName();
	void setName(string nameInput);
	double getPrice();
	void setPrice(double priceInput);
	int getQuantity();
	void setQuantity(int quantityInput);
	Biscuit();
};