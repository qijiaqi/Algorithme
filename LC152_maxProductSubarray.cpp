#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include<algorithm>

using namespace std;

int main () {
    vector<int> n;
    int size;
    cin >> size;
    int a;
    for(int i = 0; i < size; ++ i) {
        cin >> a;
        n.push_back(a);
    }

    // DP
    vector<int> mi(size, 0);
    vector<int> mx(size, 0);
    int m = n[0];
    for (int i = 1; i < size; ++ i) {
        // discrete
        // mi[i] = min(mi[i - 1], mx[i - 1]*n[i]);
        // mx[i] = max(mx[i - 1], mi[i - 1]*n[i]);
        // continue
        mi[i] = min(n[i], min(mi[i-1]*n[i], mx[i-1]*n[i]));
        mx[i] = max(n[i], max(mi[i-1]*n[i], mx[i-1]*n[i]));
        m = max(m, mx[i]);
    }   

    cout << m << endl;
    return 0;
}