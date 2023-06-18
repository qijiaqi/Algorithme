#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main () {
    vector<vector<int>> g;
    int n;
    cin >> n;
    int a;
    for (int i = 0; i < n; ++ i) {
        vector<int> l;
        for (int j = 0; j < n; ++ j) {
            cin >> a;
            l.push_back(a);
        }
        g.push_back(l);
    }

    // DP with O(n^2)
    // dp[i][j]: min path sum at the cell (line i, column j), g for the optimisation of memory
    int first_min = 0;
    int second_min = 0;
    int pos = -1;
    if (n == 1) return g[0][0];
    else {
        for(int i = 0; i < n; ++ i){
            int f = INT_MAX;
            int s = INT_MAX;
            int p = -1;
            for(int j = 0; j < n; ++ j){
                if (pos != j) g[i][j] = first_min + g[i][j];
                else g[i][j] = second_min + g[i][j];
                // renew f 
                if (f >= g[i][j]) {
                    s = f;
                    f = g[i][j];
                    p = j;
                // not renew f but need renew s
                } else if (s > g[i][j]) s = g[i][j]; 
            }
            first_min = f;
            second_min = s;
            pos = p;
        }
    }
    /*for(int i = 0; i < n; ++ i){
            for(int j = 0; j < g[i].size(); ++ j){
                cout << g[i][j] << ' ';
            }
            cout << endl;
    }*/    

    cout << first_min << endl;
    return 0;
}