#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include<algorithm>

using namespace std;

int main () {
    vector<int> n;
    int size, f;
    cin >> size >> f;
    int a;
    for(int i = 0; i < size; ++ i) {
        cin >> a;
        n.push_back(a);
    }

    // DP
    vector<vector<int>> dp(size, vector<int>(2, 0)); // dp[i][j]: max profit on day i in state j 
    dp[0][1] = -n[0];
    for (int i = 1; i < size; ++ i) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + n[i] - f); // sell
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - n[i]); // buy
    }

    cout << dp[size - 1][0] << endl;
    return 0;
}