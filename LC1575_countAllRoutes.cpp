#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

// h[pos][rest] : number of path if we use fuel less than rest to get city finish from pos city
vector<vector<int>> h;

int dfs(const vector<int>& g, int p, int f, int rest) {
    // if already computed
    if (h[p][rest] != -1) return h[p][rest];
    // if we can't reach the finish city
    if (abs(g[p] - g[f]) > rest) return 0;
    
    h[p][rest] = 0;
    for (int i = 0; i < g.size(); ++i) {
        if (p != i) {
            // path : p -> i -> finish
            int cost = abs(g[p] - g[i]);
            if (cost <= rest) h[p][rest] += dfs(g, i, f, rest - cost);
        }
    }

    // we have already gone at the finish city
    if (p == f) h[p][rest] += 1;
    return h[p][rest];
}

int main () {
    vector<int> g;
    int n, s, f, c;
    cin >> n >> s >> f >> c;
    int a;
    for (int i = 0; i < n; ++ i) {
        cin >> a;
        g.push_back(a);
    }

    // DP with O(n^3)
    // dp[pos][rest] : number of path if we use fuel rest to get city finish from pos city
    vector<vector<int>> dp (n, vector<int> (c + 1, 0));
    // if we are at the finish city
    for (int i = 0; i <= c; ++ i) dp[f][i] = 1;
    for (int t = 0; t <= c; ++ t) {
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                int cost = abs(g[i] - g[j]);
                if (i != j && t - cost >= 0) dp[i][t] += dp[j][t - cost];
            }
        }
    }

    // MS (DP & DFS): Memory search
    h.assign(n, vector<int>(c + 1, -1));

    // DFS: TIMEOUT !
    int res = 0;
    // current position
    stack<int> p;
    // current fuel
    stack<int> q;
    int x = s;
    int y = c;
    p.push(x);
    q.push(y); 
    while (!p.empty()) {
        x = p.top();
        y = q.top();
        p.pop();
        q.pop();
        if (y < 0) continue;
        if (x == f) ++ res;
        for (int i = 0; i < n; ++ i) {
            if (i == x) continue;
            p.push(i);
            q.push(y - abs(g[x] - g[i]));
        }
    }

    cout << dfs(g, s, f, c) << endl;
    cout << res << endl;
    cout << dp[s][c] << endl;
    return 0;
}