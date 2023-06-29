#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
// 576. Out of Boundary Paths
int main () {
    int m, n, mv, sm, sn;
    cin >> m >> n >> mv >> sm >> sn;

    // DP with O(n^3)
    // dp[i][j][k] : number of path if we'are at position (i, j) with k move
    vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (mv + 1, 0)));
    dp[sm][sn][0] = 1;
    int path = 0;
    for (int k = 0; k < mv; ++ k) {
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                // count if only at the bound
                // UP
                if (i != m-1) dp[i+1][j][k+1] += dp[i][j][k];
                else path += dp[i][j][k];
                // DOWN
                if (i != 0) dp[i-1][j][k+1] += dp[i][j][k];
                else path += dp[i][j][k];
                // RIGHT
                if (j != n-1) dp[i][j+1][k+1] += dp[i][j][k];
                else path += dp[i][j][k];
                // LEFT
                if (j != 0) dp[i][j-1][k+1] += dp[i][j][k];
                else path += dp[i][j][k];
            }
        }
    }

    cout << path << endl;
    return 0;
}