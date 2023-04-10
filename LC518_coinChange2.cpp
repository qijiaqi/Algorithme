#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include<algorithm>

using namespace std;

int main () {
    vector<int> n;
    int size, k;
    cin >> size >> k;
    int a;
    for(int i = 0; i < size; ++ i) {
        cin >> a;
        n.push_back(a);
    }

    // DP
    vector<int> dp(k + 1, 0); // times
    dp[0] = 1;
    for (int i = 0; i < size; ++ i) {
        for (int j = 0; j <= k - n[i]; ++ j) { // Overflow
            dp[j + n[i]] += dp[j];
        }
    }

    cout << dp[k] << endl;
    return 0;
}