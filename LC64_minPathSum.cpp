#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include<algorithm>

using namespace std;

int main () {
    vector<vector<int>> g;
    int m, n;
    cin >> m >> n;
    int a;
    for (int i = 0; i < m; ++ i) {
        vector<int> l;
        for (int j = 0; j < n; ++ j) {
            cin >> a;
            l.push_back(a);
        }
        g.push_back(l);
    }

    // DP with O(n^2)
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX)); // dp[i][j]: max sum at the cell (line i, column j)
    dp[0][0] = g[0][0];
    for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (i - 1 >= 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + g[i][j]); 
            if (j - 1 >= 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + g[i][j]); 
        }
    }

    cout << dp[m - 1][n - 1] << endl;
    return 0;
}