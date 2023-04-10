#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include<algorithm>

using namespace std;

int main () {
    vector<int> n;
    int size, k;
    cin >> size >> k;
    int a;
    for(int i = 0; i < size; ++ i) {
        cin >> a;
        n.push_back(a);
    }

    // DP with O(n^2)
    vector<int> dp(k + 1, INT_MAX); // // dp[i]: min number of coins to change the money i
    dp[0] = 0;
    for (int i = 0; i < size; ++ i) {
        for (int j = 0; j <= k - n[i]; ++ j) { // overflow
            if (dp[j] != INT_MAX) {
                dp[j + n[i]] = min(dp[j + n[i]], dp[j] + 1);
            }
        }
    }

    if (dp[k] == INT_MAX) cout << -1 << endl;
    else cout << dp[k] << endl;
    return 0;
} 