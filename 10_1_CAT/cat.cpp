#include <fstream>
#include<iostream>

using namespace std;

int main() 
{ 
    string str;
   ifstream ifile;
 
   ifile.open("normal.txt");
 
   if(ifile) 
   {
    while(getline(ifile, str))
    {
        cout << str;
    }
   } 
   else 
   {
      cout<<"File does not exist";
   }
}