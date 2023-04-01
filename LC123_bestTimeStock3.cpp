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
    vector<vector<int>> dp(size, vector<int>(4, 0)); 
    dp[0][0] = -n[0]; // 0: stock in hand
    dp[0][2] = -n[0]; // 2: stock in hand at the second time
    for (int i = 1; i < size; ++ i) { 
        dp[i][0] = max(dp[i - 1][0], -n[i]); // buy
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + n[i]); // sell
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - n[i]); // buy
        dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + n[i]); // sell
    }

    cout << dp[size - 1][3] << endl;
    return 0;
}