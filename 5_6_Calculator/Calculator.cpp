//Design a calculator for integer and float values
#include <iostream>
#include <climits>
#include <stdexcept>

using namespace std;

int main()
{
    
    int operation;
    cout << "Enter 1 for integer or 2 for float Operation:";
    cin >> operation;

    if(operation == 1)
    {

        int a, b, c;
        char o;
        cout << "Enter the Operation and then the values : ";
        cin >> o >> a >> b ;

        switch (o)
   {
    case '+':
        c = a + b;
        break;

    case '-':
        c = a - b;
        break;

    case '/':
        c = a / b;
        break;    
    
    case '*':
        c = a * b;
        break;

    default:
        c = 0;
        break;
   }
   cout << c;

   }


    else if(operation == 2)
  {

    float l, m, n;
    char type;
    cout << "Enter the Operation and then the values : ";
    cin >> type >> l >> m ;

  switch (type)
 {
    case '+':
        n = l + m;
        break;

    case '-':
        n = l - m;
        break;

    case '/':
        n = l / m;
        break;    
    
    case '*':
        n = l * m;
        break;

    default:
        n = 0;
        break;
   }
   cout<<n;
   }

   else
   cout <<"Invalid";
}