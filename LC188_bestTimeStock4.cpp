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

    // DP
    vector<vector<int>> dp(size, vector<int>(2*k, 0)); // dp[i][j]: max profit on day i in state j 
    for (int i = 0; i < 2*k; i += 2) dp[0][i] = -n[0]; 
    for (int i = 1; i < size; ++ i) { 
        dp[i][0] = max(dp[i - 1][0], -n[i]); // buy
        for (int j = 1; j < 2*k; ++ j) {
            if (j%2) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + n[i]); // sell
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - n[i]); // buy
        }
    }

    cout << dp[size - 1][2*k - 1] << endl;
    return 0;
}