//Closest to zero (Given a list of integers, find the closest to zero.If there is a tie, choose the positive value.)
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
 
int main() {
    int x[] = {2, 0, 1, 5, 6, 4, 3, -2, -1};
    int len = sizeof(x) / sizeof(x[0]);
     
    sort(x, x + len);

    for(int i = 0; i < len; i++)
    {
        if(x[i] == 0 && x[i + 1] > x[i - 1])
        {
            cout << "Closest to zero element is : " << x[i + 1]; 
        }
    }

    cout << endl;
}