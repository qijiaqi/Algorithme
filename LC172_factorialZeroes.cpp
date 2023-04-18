#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include<algorithm>

using namespace std;

int main () {
    int n;
    cin >> n;

    // BF with O(n)
    int n10 = 0, s = 1;
    for (int i = 2; i <= n; ++ i) {
        s *= i; // overflow
        while (s%10 == 0) {
            s /= 10;
            ++ n10;
        }
    }
    // factor 2 & 5 minimum counting with O(n)
    int n5 = 0;
    for (int i = 2; i <= n; ++ i) {
        int j = i;
        while (j%5 == 0) {
            ++ n5;
            j /= 5;
        }
    }
    // optimisation with O(logn)
    // only factor 5 counting with sum(floor(n/5^k))
    int m = 0;
    while (n) {
        n /= 5;
        m += n;
    }

    cout << n10 << " " << n5 << " " << m << endl;
    return 0;
}