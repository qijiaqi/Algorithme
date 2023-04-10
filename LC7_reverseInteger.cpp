#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main () {
    int x, c;
    cin >> x;
    c = x;

    int y = 0;
    if (x > INT_MIN) { // INT_MAX = 2147483647, INT_MIN = -2147483648
        while (x != 0) {
            int z = x%10;
            if ( 214748364 > abs(y) || (abs(y) == 214748364 && z < 7) ) y = y*10 + z; 
            // round problem: (INT_MAX - z)/10
            else {
                y = 0;
                break;
            }
            x /= 10;
        }
    }
    // conversion: long y == (int)y
    int a = 0;
    while (c != 0) {
        a = a*10 + c%10;
        c /= 10;
    }
    int b = (a == (int)a) ? a : 0; // 0 if overflow

    cout << y << " " << b << endl;
    return 0;
}