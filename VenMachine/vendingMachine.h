#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cerrno>
#include <cstdlib>

#define MAX_COLA_COUNT  1
#define MAX_CHIPS_COUNT 1
#define MAX_CANDY_COUNT 1

#define MAX_NICKEL_COUNT_IN_VM 100
#define MAX_DIME_COUNT_IN_VM 100
#define MAX_QUARTER_COUNT_IN_VM 100

using namespace std;

class Menu
{
    protected:
    unsigned char chooseItem;
    unsigned int itemsCount;
    int itemsPrice;
    unsigned int itemsPrice_cola;
    unsigned int itemsPrice_chips;
    unsigned int itemsPrice_candy;
    map<string, unsigned int>itemsList;

    public:
    int itemCount_cola;
    int itemCount_chips;
    int itemCount_candy;
    int itemsLeft_cola;
    int itemsLeft_chips;
    int itemsLeft_candy;
    void welcome() const;
    void listOfItems();
};

class Vending_Machine: public Menu
{
    private:
    unsigned int insertedCoins;
    unsigned char currencyMode;
    unsigned int numberOfCoins_nickel;
    unsigned int numberOfCoins_dime;
    unsigned int numberOfCoins_quarter;
    int totalAmount; 
    unsigned int totalAmount_nickel; 
    unsigned int totalAmount_dimes; 
    unsigned int totalAmount_quarter; 
    unsigned int totalCurrencyInVendingMachine;
    map<string, unsigned int> currencyCountInVendingMachine;

    public:
    void acceptMultipleCoins();
    unsigned int calculateTotalCoins();
    void selectAndPurchaseItems();
    bool checkAvailability();
    void calculateTotalPrice();
    void balanceAmount();
    void exactChange();
};