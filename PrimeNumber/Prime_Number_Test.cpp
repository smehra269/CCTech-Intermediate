#include <iostream>
#include <cassert>
#include "Prime_Number.h"
#include "Prime_Number.cpp"

using namespace std;

int main(){
    assert(is_prime(2) == true);
    assert(is_prime(3) == true);
    assert(is_prime(4) == false);
    assert(is_prime(5) == true);
    cout <<"All test cases passed.";
}