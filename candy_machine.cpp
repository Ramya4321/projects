/*
A common place to buy candy is from a machine. 
The machine sells candies, chips, gum, and cookies.
You have been asked to write a program for this candy machine.
The program should do the following:
1. Show the customer the different products sold by the candy machine.
2. Let the customer make the selection.
3. Show the customer the cost of the item selected.
4. Accept money from the customer.
5. Release the item.
 The machine has two main components: a built-in cash register and 
several dispensers to hold and release the products.

Define class cashRegister in C++ with the following descriptions :
Private Members:
cashOnHand of type integer
Public Members:
A default constructor cashRegister() sets the cash in the register to 500.
A constructor cashRegister(int) sets the cash in the register to a specific amount.
A function getCurrentBalance() which returns value of cashOnHand
A function acceptAmount(int) to receive the amount deposited by the customer
 and update the amount in the register
Define class dispenserType in C++ with the following descriptions :
Private Members:
numberOfItems of type integer
cost of type integer
Public Members:
A default constructor dispenserType () sets the cost and number of
 items in the dispenser to 50 each.
A constructor dispenserType (int,int) sets the cost and number of items in the dispenser
 to the values specified by the user.
A function getNoOfItems() to return the value of numberOfItems.
A function getCost() to return the value of cost.
A function makeSale() to reduce the number of items by 1.
When the program executes, it must do the following:
1. Show the different products sold by the candy machine.
2. Show how to select a particular product.
Once the user has made the appropriate selection, the candy machine must act accordingly. 
If the user has opted to buy a product and that product is available, 
the candy machine should show the cost of the product and ask the user to deposit the money. 
If the amount deposited is at least the cost of the item, the candy machine should sell the 
item and display an appropriate message.
Divide this program into three functions: showSelection, sellProduct, and main.
The function sellProduct must have access to the dispenser holding the product 
(to decrement the number of items in the dispenser by 1 and to show the cost of the item)
 as well as the cash register (to update the cash). 
 Therefore, this function has two parameters: one corresponding to the dispenser
 and the other corresponding to the cash register.
*/
#include<iostream>
using namespace std;
//void showSelection();
//void sellProduct(dispenserType& product, cashRegister& pCounter);
class cash_register
{
	private:
		int cash_on_hand;
	public:
		cash_register()
		{
			cash_on_hand=500;
		}
		cash_registor(int cashIn)
		{
			cash_on_hand=cashIn;
		}
		int get_current_balance()
		{
		return cash_on_hand;
		}
		int accept_amount(int amount_in)
		{
		cash_on_hand=cash_on_hand+amount_in;
		}
		
};
class dispenser_type
{
	int number_of_items;
	int cost;
	public:
		dispenser_type()
		{
			number_of_items=50;
			cost=50;
		}
		dispenser_type(int setNumberOfItems,int SetCost)
		{
			number_of_items=setNumberOfItems;
			cost=SetCost;
		}
		int get_number_of_items()
		{
			return number_of_items;
		}
		int getcost()
		{
			return cost;
		}
		int makesale()
		{
			number_of_items--;
		}
};
void showSelection()
{
	cout << "*** Welcome to Candy Shop ***" << endl;
	cout << "To select an item, enter " << endl;
	cout << "1 for Candy" << endl;
	cout << "2 for Chips" << endl;
	cout << "3 for Gum" << endl;
	cout << "4 for Cookies" << endl;
	cout << "5 to exit" << endl;
}
void sellProduct(dispenser_type& product, cash_register& pCounter)
{
	int amount; //variable to hold the amount entered
	int amount2; //variable to hold the extra amount needed
	if (product.get_number_of_items() > 0) //if the dispenser is not empty
	{
		cout << "Please deposit " << product.getcost() << " cents" << endl;
		cin >> amount;
		if(amount < product.getcost())
		{
			cout << "Please deposit another " << product.getcost()- amount << " cents" << endl;
			cin >> amount2;
			amount = amount + amount2;
		}
		
		if (amount >= product.getcost())
		{
			pCounter.accept_amount(amount);
			product.makesale();
			cout << "Collect your item at the bottom and " << "enjoy." << endl;
			cout<<"collect your extra amount"<<amount- product.getcost()<<endl;
		}

		else
			cout << "The amount is not enough. " << "Collect what you deposited." << endl;
		cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
	}
	else
		cout << "Sorry, thisitem is sold out"<<endl;
	}
int main()
{
	cash_register counter;
	dispenser_type candy(100, 50);
	dispenser_type chips(100, 65);
	dispenser_type gum(75, 45);
	dispenser_type cookies(50, 85);
	int choice;
	showSelection();
	cin >> choice;
	while (choice != 5)
	{
		switch (choice)
		{
			case 1:
				sellProduct(candy, counter);
				break;
			case 2:
				sellProduct(chips, counter);
				break;
			case 3:
				sellProduct(gum, counter);
				break;
			case 4:
				sellProduct(cookies, counter);
				break;
			default:
				cout << "Invalid selection." << endl;
		}
		showSelection();
		cin >> choice;
	}	
	return 0;
}
	
