#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main () {
    vector<string> f;
    int l;
    cin >> l;
    for (int i = 0; i < l; ++ i) {
        string s;
        cin >> s;
        f.push_back(s);
    }


    // DP with O(n^2)
    // dp[i][j]: max score at position (i, j)
    // np[i][j] : number of path with max score at position (i, j)
    int m = f.size();
    int n = f[0].size(); 
    int t;
    vector<vector<int>> dp (m, vector<int> (n, 0));
    vector<vector<int>> np (m, vector<int> (n, 0));
    np[m-1][n-1] = 1;
    // center
    for (int i = m - 1; i >= 0; -- i) {
        for (int j = n - 1; j >= 0; -- j) {
            // X & S
            if (dp[i][j] == 0 && f[i][j] != 'S') continue;
            // UP
            if (i != 0 && f[i-1][j] != 'X') {
                // E
                if (f[i-1][j] == 'E') t = 0;
                else t = f[i-1][j]-'0';
                if (dp[i][j] > dp[i-1][j] - t) {
                    np[i-1][j] = np[i][j];
                    dp[i-1][j] = dp[i][j] + t;
                } else if (dp[i][j] == dp[i-1][j] - t) np[i-1][j] += np[i][j];
            }
            // LEFT
            if (j != 0 && f[i][j-1] != 'X') {
                // E
                if (f[i][j-1] == 'E') t = 0;
                else t = f[i][j-1]-'0';
                if (dp[i][j] > dp[i][j-1] - t) {
                    np[i][j-1] = np[i][j];
                    dp[i][j-1] = dp[i][j] + t;
                } else if (dp[i][j] == dp[i][j-1] - t) np[i][j-1] += np[i][j];
            }
            // UP-LEFT
            if (i != 0 && j != 0 && f[i-1][j-1] != 'X') {
                // E
                if (f[i-1][j-1] == 'E') t = 0;
                else t = f[i-1][j-1]-'0';
                if (dp[i][j] > dp[i-1][j-1] - t) {
                    np[i-1][j-1] = np[i][j];
                    dp[i-1][j-1] = dp[i][j] + t;
                } else if (dp[i][j] == dp[i-1][j-1] - t) np[i-1][j-1] += np[i][j];
            }
        }
    }

    // debug
    /*for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < n; ++ j) {
            cout << dp[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < n; ++ j) {
            cout << np[i][j]<<" ";
        }
        cout << endl;
    }*/

    cout << dp[0][0] << " " << np[0][0] << endl;
    return 0;
}