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
    vector<vector<int>> dp(size, vector<int>(4, 0)); // dp[i][j]: max profit on day i in state j 
    dp[0][0] = -n[0];
    for (int i = 1; i < size; ++ i) {
        dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][3]) - n[i]); // buy
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]); // stock not in hand
        dp[i][2] = dp[i - 1][0] + n[i]; // sell & cooldown
        dp[i][3] = dp[i - 1][2]; // free
    }

    cout << max(dp[size - 1][1], max(dp[size - 1][2], dp[size - 1][3])) << endl;
    return 0;
    } 