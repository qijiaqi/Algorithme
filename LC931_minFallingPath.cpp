#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main () {
    vector<vector<int>> g;
    int m;
    cin >> m;
    int a;
    for (int i = 0; i < m; ++ i) {
        vector<int> l;
        for (int j = 0; j < m; ++ j) {
            cin >> a;
            l.push_back(a);
        }
        g.push_back(l);
    }
    
    // DP with O(n^2)
    // dp[i][j]: min path sum at the cell (line i, column j), g for the optimisation of memory
    int res = INT_MAX;
    if (m == 1) return g[0][0];
    else {
        for(int i = 1; i < m; ++ i){
            for(int j = 0; j < m; ++ j){
                if (j == 0) g[i][j] = min(g[i - 1][j], g[i - 1][j + 1]) + g[i][j];
                else if (j == m-1) g[i][j] = min(g[i - 1][j], g[i - 1][j - 1]) + g[i][j];
                // if not at the two boards
                else g[i][j] = min(g[i - 1][j], min(g[i - 1][j - 1], g[i - 1][j + 1])) + g[i][j];
                // renew the min path sum of the last line
                if (i == m - 1 && res > g[i][j]) res = g[i][j];
            }
        } 
    }   

    cout << res << endl;
    return 0;
}
