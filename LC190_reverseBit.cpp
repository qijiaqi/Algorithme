#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <stdint.h>
#include<algorithm>

using namespace std;

int main () {
    unit32_t n;
    cin >> n;

    // Bit
    unit32_t m = 0;
    for (int i = 1; i <= 32; ++ i) {
        m |= (n & 1) << (32 - i);
        n >>= 1; 
    }

    cout << m << endl;
    return 0;
}