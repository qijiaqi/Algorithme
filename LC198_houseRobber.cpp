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
    if (size == 0) cout << 0 << endl;
    if (size == 1) cout << n[1] << endl;
    vector<int> dp(size, 0);
    dp[0] = n[0], dp[1] = max(dp[0], n[1]);
    for (int i = 2; i < size; ++ i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + n[i]);
    }

    if (size > 1) cout << dp[size - 1] << endl;
    return 0;
}