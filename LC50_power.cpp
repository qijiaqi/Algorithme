#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include<algorithm>

using namespace std;

int main () {
    double x;
    int n;
    cin >> x >> n;

    // positive
    bool f = true;
    if (n < 0) f = false; 
    // quick power with O(logn): x^n = (x^(2^b1))*...*(x^(2^bm))
    // bk: k th binary bit of n counted from right to left which equals one 
    // Timeout with O(n): res *= x; -- n;
    double res = 1, base = x;
    while (n) {
        if (abs(n%2) == 1) res *= base;
        // only compute when binary bit equals one    
        base *= base; // x x^2 x^4 x^8 x^16 ... 
        n /= 2; 
    }

    if (!f) cout << 1/res << endl;
    else cout << res << endl;
    return 0;
}