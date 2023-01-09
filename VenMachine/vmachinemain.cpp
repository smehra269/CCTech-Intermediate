#include "vendingMachine.h"

using namespace std;

int main(int argc, char* argv[])
{
    Menu menu;
    menu.welcome();
    menu.listOfItems();

    Vending_Machine vm;
    vm.acceptMultipleCoins();
    vm.calculateTotalCoins();
    vm.selectAndPurchaseItems();
    vm.calculateTotalPrice();
    vm.balanceAmount();
    vm.exactChange();
    vm.checkAvailability();
    return 0;
}