#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include<algorithm>

using namespace std;

int main () {
    int n;
    cin >> n;

    int m = n;
    // Timeout
    int i = 1; // i th round 
    vector<int> l(n, -1);
    // Simulation
    while (n) {
        for (int j = i - 1; j < l.size();  j += i) { // index = i - 1
            l[j] *= -1;
        }
        -- n;
        ++ i;
    }
    // compute
    i = 0;
    for (int a : l) {
        if (a == 1) ++ i;
    }
    cout << i << " ";
    // Square number: odd number of factors
    i = 0;
    while (i*i <= m) ++ i;
    cout << i - 1 << endl;
    return 0;
}