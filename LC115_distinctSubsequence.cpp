#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include<algorithm>

using namespace std;

int main () {
    string s, t;
    cin >> s >> t;

    // DP with O(n^2)
    vector<vector<int>> dp(t.size() + 1, vector<int>(s.size() + 1, 0)); 
    // dp[i][j]: max frequence of subsequence of t with size i in subsequence of s with size j
    for (int j = 0; j <= s.size(); ++ j) dp[0][j] = 1; 
    for (int i = 1; i <= t.size(); ++ i) {
        for (int j = 1; j <= s.size(); ++ j) {
            if (s[j - 1] == t[i - 1] && dp[i - 1][j - 1] < INT_MAX - dp[i][j - 1]) { // overflow
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1]; // (ba, babgba) = (ba, babgb) + (b, babgba)
            } else {
                dp[i][j] = dp[i][j - 1]; // (b, ba) = (b, b) where (i, j) correponds (t, s)
            }
        }
    }
    /*      table of DP
               j for s  
            0 b a b g b a g
    i     0 1 1 1 1 1 1 1 1 
    for   b 0 1 1 2 2 3 3 3
    t     a 0 0 1 1 1 1 4 4
          g 0 0 0 0 1 1 1 5
    */

    cout << dp[t.size()][s.size()] << endl;
    return 0;
}