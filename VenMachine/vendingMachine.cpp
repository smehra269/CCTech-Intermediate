#include "vendingMachine.h"

using namespace std;

void Menu::welcome() const
{
    cout << "Welcome to the Vending machine!!!" << endl;
}

void Menu::listOfItems()
{
    itemsList["Cola"]  = 100;
    itemsList["Chips"] = 50;
    itemsList["Candy"] = 65;

    map<string, unsigned int>::iterator itr = itemsList.begin();
    cout << "The items and their rates are :" << endl;
    while (itr != itemsList.end())
    {
        cout << itr->first << " : " << itr->second << " cents"<<endl;
        ++itr;
    }
    cout<<"*****************************"<<endl;

}

void Vending_Machine::acceptMultipleCoins()
{
    cout << "Please enter the number of coins in multiples of nickel (5 cents), dime (10 cents), and quarter (25 cents)." << endl;
    cout << "Single pennies are not allowed." << endl;
    cout << "#####################################" << endl;

    cout << "Number of nickels (5 cents): ";
    cin >> numberOfCoins_nickel;
    cout << "Number of dimes (10 cents): ";
    cin >> numberOfCoins_dime;
    cout << "Number of quarters (25 cents): ";
    cin >> numberOfCoins_quarter;

    totalAmount_nickel = numberOfCoins_nickel * 5;
    totalAmount_dimes = numberOfCoins_dime * 10;
    totalAmount_quarter = numberOfCoins_quarter * 25; 

    cout << "******************************" << endl;
}


unsigned int Vending_Machine::calculateTotalCoins()
{
    cout << "MESSAGE: Start inserting your coins inside the vending machine." << endl;
    totalAmount = totalAmount_nickel + totalAmount_dimes + totalAmount_quarter;
    cout << "You have inserted a total of " << totalAmount_nickel << " cents in nickels, " << totalAmount_dimes << " cents in dimes, and " << totalAmount_quarter << " cents in quarters." << endl;
    cout << "This adds up to a total of " << totalAmount << " cents." << endl;
    cout << "******************************" << endl;
    
    return totalAmount;
}


void Vending_Machine::selectAndPurchaseItems()
{
    cout << "Please select from the following items: COLA, CHIPS, CANDY" << endl;
    cout << "Enter the number of COLA items you would like to purchase: ";
    cin >> itemCount_cola;
    itemsLeft_cola = MAX_COLA_COUNT - itemCount_cola;

    cout << "Enter the number of CHIPS items you would like to purchase: ";
    cin >> itemCount_chips;
    itemsLeft_chips = MAX_CHIPS_COUNT - itemCount_chips;

    cout << "Enter the number of CANDY items you would like to purchase: ";
    cin >> itemCount_candy;
    itemsLeft_candy = MAX_CANDY_COUNT - itemCount_candy;

    cout << "******************************" << endl;
}


bool Vending_Machine::checkAvailability()
{
    bool soldOut = false;

    if (itemCount_cola > itemsLeft_cola)
    {
        cerr << "Sorry, only " << MAX_COLA_COUNT << " colas are available." << endl;
        soldOut = true;
    }
    if (itemCount_chips > itemsLeft_chips)
    {
        cerr << "Sorry, only " << MAX_CHIPS_COUNT << " chips are available." << endl;
        soldOut = true;
    }
    if (itemCount_candy > itemsLeft_candy)
    {
        cerr << "Sorry, only " << MAX_CANDY_COUNT << " candy are available." << endl;
        soldOut = true;
    }

    return soldOut;
}


void Vending_Machine::calculateTotalPrice()
{
    itemsPrice_cola = itemCount_cola * 100;
    itemsPrice_chips = itemCount_chips * 50;
    itemsPrice_candy = itemCount_candy * 65;

    cout << "Calculating the total price of your items:" << endl;
    cout << "COLA: $" << itemsPrice_cola / 100.0 << endl;
    cout << "CHIPS: $" << itemsPrice_chips / 100.0 << endl;
    cout << "CANDY: $" << itemsPrice_candy / 100.0 << endl;

    itemsPrice = itemsPrice_cola + itemsPrice_chips + itemsPrice_candy;
    cout << "Total price: $" << itemsPrice / 100.0 << endl;
    cout << "You have inserted a total of " << totalAmount << " cents." << endl;

    cout << "******************************" << endl;
}


void Vending_Machine::balanceAmount()
{
    if(itemsPrice>totalAmount)
    {
        cout<<"You need to insert ("<<itemsPrice<<" - "<<totalAmount<<") = "<< itemsPrice-totalAmount<<" more cents"<<endl;
    }
    else if(itemsPrice<totalAmount)
    {
        cout<<"Returning your balance amount: ("<<totalAmount<<" - "<<itemsPrice<<") = "<<totalAmount-itemsPrice<<" cents"<<endl;
    }

    cout<<"******************************"<<endl;
}

void Vending_Machine::exactChange()
{
    totalCurrencyInVendingMachine=(MAX_NICKEL_COUNT_IN_VM * 5)+ (MAX_DIME_COUNT_IN_VM * 10) + (MAX_QUARTER_COUNT_IN_VM * 25);

    if((totalAmount-itemsPrice)>totalCurrencyInVendingMachine)
    {
        cerr<<"Warning: This vending machine does not have change of "<< abs(itemsPrice-totalAmount)<<" cents"<<endl;
        cerr<<"Please insert exact change of: "<<itemsPrice<< " cents"<<endl;
    }
    else if((totalAmount-itemsPrice)<totalCurrencyInVendingMachine)
    {
        totalCurrencyInVendingMachine-(totalAmount-itemsPrice);
    }
}