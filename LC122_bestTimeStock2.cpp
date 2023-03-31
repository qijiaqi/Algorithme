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
    vector<vector<int>> dp(size, vector<int>(2, 0)); 
    dp[0][1] = -n[0]; // 1: stock in hand
    for (int i = 1; i < size; ++ i) { 
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - n[i]); // can buy several times
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + n[i]);
    }
    // GR
    int sum = 0, min = n[0];
    for (int i = 1; i < size; ++ i) {
        if (min < n[i]) sum += n[i] - min;
        min = n[i];
    }

    cout << dp[size - 1][0] << " " << sum << endl;
    return 0;
}