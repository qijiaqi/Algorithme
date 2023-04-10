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

    // DP with O(n^2)
    int res = 1;
    vector<int> dp(size, 1); // dp[i]: longest length which ends with n[i]
    for (int i = 1; i < size; ++ i) {
        for (int j = 0; j < i; ++ j) {
            if (n[i] > n[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
                res = max(res, dp[i]);
            }
        }
    }

    cout << res << endl;
    return 0;
}