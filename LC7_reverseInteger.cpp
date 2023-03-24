#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main () {
    int x;
    cin >> x;

    int y = 0, z = 1; // long y, (int)y
        if(x < 0) {
            z = -1;
            if(x > INT_MIN) x *= -1; // x = INT_MIN
            else return 0;
        }
        while(x != 0) {
            int tmp = x%10;
            if( 214748364 > y || (y == 214748364 && tmp < 7) ) y = y*10 + tmp; // (INT_MAX - tmp)/10
            else return 0;
            x /= 10;
        }

    cout << y*z;
    return 0;
}