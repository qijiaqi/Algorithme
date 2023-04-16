#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include<algorithm>

using namespace std;

int main () {
    int n;
    cin >> n;

    int a = 0, b = 0;
    // BF with O(n*n^1/2)
    for (int i = 2; i < n; ++ i) {
        for (int j = 2; j <= sqrt(i); ++ j) { // try until sqrt(i)
            if (i%j == 0) {                   // if i isn't prime
                -- a;
                break;
            }
        }
        ++ a;
    }
    // Eratosthenes with O(n*loglogn)
    vector<bool> p(n, true);
    for (int i = 2; i < n; ++ i) {
        if (p[i]) ++ b;
        // if ((long long) i*i >= n) continue; // overflow && j*1 is prime
        for (int j = i; j < n; j += i) { // i*i
            if (i != j) p[j] = false;
        }
    }

    cout << a << " " << b << endl;
    return 0;
}