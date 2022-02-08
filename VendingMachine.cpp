// VendingMachine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "item.h"
#include <map>
#include "User.cpp"
#include "Retailer.cpp"

void UserWorkFlow()
{    
    try
    {
        while (true)
        {
            int optionCount = 1, userChoice = 0;
            map<int, Item*> itemsMap;
            cout << "Make a choice" << endl;
            cout << 0 << ": " << "Exit" << endl;
            for (Item* itemToDisplay : Item::getItemColl())
            {
                cout << optionCount << ": " << itemToDisplay->getName() <<", available quantity: "<<
                    itemToDisplay->getQuantity()<<" and is priced at: "<< itemToDisplay->getPrice() << endl;
                itemsMap[optionCount++] = itemToDisplay;
                //++option;
            }

            cout << optionCount << ": " << "Recharge" << endl;
            cin.clear();
            cin >> userChoice;
            if (userChoice == 0)
            {
                cout << "Thank you. Visit again!" << endl;
                break;
            }
            else if (userChoice == optionCount)
            {
                cout << "Select the amount to recharge with :" << endl;
            }
            else if(userChoice > 0 && userChoice <= itemsMap.size())
            {
                int quantityToDispatch = 0;
                cout << "You have selected: " << itemsMap[userChoice]->getName() << " , it's price is: " << itemsMap[userChoice]->getPrice();
                cout << " and " << itemsMap[userChoice]->getQuantity() << " are available" << endl;
                cout << "Enter quantity to dispatch: " << endl;
                cin.clear();
                cin >> quantityToDispatch;

                int returnCode = User::DispatchAndManage(itemsMap[userChoice], quantityToDispatch);

                if (returnCode < 0)
                    cout << "Unable to Dispatch selected item. Please try again." << endl;
                else
                    cout << "Successfully dispatched the selected item." << endl;
            }
        }
    }
    catch(exception ex)
    {
        throw;
    }
}
void RetailerWorkFlow()
{
    try
    {
        while (true)
        {
            cout << "Select item to Add, Modify or Remove:" << endl;
            int optionCount = 1;
            cout << 0 << ": " << "Return to Main Menu" << endl;
            map<int, Item*> itemsMap;
            for (Item* itemToDisplay : Item::getItemColl())
            {
                cout << optionCount << ": " << itemToDisplay->getName() << ", available quantity: " <<
                    itemToDisplay->getQuantity() << " and is priced at: " << itemToDisplay->getPrice() << endl;;
                itemsMap[optionCount++] = itemToDisplay;
            }

            int retailerChoice = 0;
            cin.clear();
            cin >> retailerChoice;
            if (retailerChoice == 0)
            {
                //cout << "Thank you!" << endl;
                break;
            }
            else if(retailerChoice > 0 && retailerChoice <= itemsMap.size())
            {
                while (true)
                {
                    int retailerChoice2 = 0;
                    cout << "You have selected: " << itemsMap[retailerChoice]->getName() << " , it's price is: " << itemsMap[retailerChoice]->getPrice();
                    cout << " and " << itemsMap[retailerChoice]->getQuantity() << " are available" << endl;
                    cout << "What do you want to change? " << endl;
                    cout << "Enter 1 to change the Quantity available" << endl;
                    cout << "Enter 2 to change the Price of the item" << endl;
                    cout << "Enter 0 to return to the previous menu" << endl;
                    cin.clear();
                    cin >> retailerChoice2;
                    if (retailerChoice2 == 0)
                        break;
                    else
                    {
                        int returnCode = Retailer::ModifyItems(itemsMap[retailerChoice], retailerChoice2);
                        if (returnCode < 0)
                            cout << "Unable to Modify the selected Item. Please Try again!" << endl;
                        else
                            cout << "Successfully updated the Catalog" << endl;
                        break;
                    }

                }
            }
        }
    }
    catch (exception ex)
    {
        throw;
    }
}
int main()
{
    try
    {
        cout << "Welcome!\n";
        int userType = 0;
        while (true)
        {
            cout << "Enter 1 for Customer Menu, 2 for Retailer Options and 0 to Exit!\n";
            cin.clear();
            cin >> userType;

            if (userType == 1)
            {
                UserWorkFlow();
                //break;
            }
            else if (userType == 2)
            {
                RetailerWorkFlow();
                //break;
            }
            else if (userType == 0)
            {
                cout << "Thank you. Visit again!" << endl;
                return 1;
            }
            else
                cout << "Please Make a Valid choice:";
        }
    }
    catch (exception ex)
    {
        cout << "Error executing your choice. Sorry for the inconvinience!" << endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
