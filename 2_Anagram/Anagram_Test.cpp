//Write a program to generate all potential anagrams of an input string.
#include <iostream>
#include <cassert>
#include "Anagram.cpp"
//#include "Anagram.h"

using namespace std;
 
int main()
{
    string str = "ABCD";
    //int n = str.size();
    //permute(str, 0, n-1);
    assert(permute(str, 0, str.size() - 1 ));
    //permute(str,0, str.size() - 1 );

    return 0;
}