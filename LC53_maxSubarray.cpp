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
    // vector<int> dp(size, 0);
    // dp[0] = n[0];
    // int sum = n[0];
    // for (int i = 1; i < size; ++ i) { // begin at 1
    //     dp[i] = max(dp[i - 1] + n[i], n[i]);
    //     sum = max(sum, dp[i]);
    // }
    // GR
    int sum = n[0];
    for (int i = 1; i < size; ++ i) { // begin at 1
        if (n[i - 1] > 0) n[i] += n[i - 1];
        sum = max(sum, n[i]);
    }

    cout << sum << endl;
    return 0;
}