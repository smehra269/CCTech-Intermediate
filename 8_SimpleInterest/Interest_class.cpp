//Using C++ classes implement a Simple Interest Calculator
#include <iostream>

using namespace std;

class interest
{
    float p, r, t, i;

    public : void input()
    {
        cout << "Enter Principle Amount : ";
        cin >> p;
        cout << "Enter Rate : ";
        cin >> r;
        cout << "Enter Time : ";
        cin >> t;
    }


    public : void calculation()
    {
     i = (p * r * t)/100;   
    }


    public : void output()
    {
        cout << "Interest : " << i;
    }

};

int main()
{
    interest in;
    in.input();
    in.calculation();
    in.output();
}