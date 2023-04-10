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
    vector<int> dp(size, 0); // dp[i]: largest sum which end with n[i]
    dp[0] = n[0];
    int sum = n[0];
    for (int i = 1; i < size; ++ i) { // begin at 1
        dp[i] = max(dp[i - 1] + n[i], n[i]);
        sum = max(sum, dp[i]);
    }
    // GR
    int res = n[0];
    for (int i = 1; i < size; ++ i) { // begin at 1
        if (n[i - 1] > 0) n[i] += n[i - 1]; 
        // add n[i - 1], if it's positive, we can always get a larger number
        res = max(res, n[i]);
    }

    cout << sum << " " << res << endl;
    return 0;
}