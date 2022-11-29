//Find the square root of a number and handle the invalid inputs using exception handling.
#include <iostream>
#include <cmath>

using namespace std;

class SquareRoot
{
    float num, out;

    public : void input()
    {
        cout << "Enter any number : ";
        cin>> num;     
    }


    public : void output()
    {
        try{
             if(num != 0)
            {
                       out = sqrt(num);
                       cout << "Squareroot of "<< num <<" is : " << out;
            } 
            else
            throw 200;
           }

           catch(int mynum)
           {
            cout << "0 is Invalid and Error number is : " <<mynum;
           }
    }

};

int main()
{
    SquareRoot s;
    s.input();
    s.output();
}