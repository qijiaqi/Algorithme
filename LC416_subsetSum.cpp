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
    int sum = 0;
    for (int i = 0; i < size; ++ i) sum += n[i]; // border: sum/2 < 100*200/2 + 1
    if (sum%2 == 1) {
        cout << false << endl; // odd%2 = 1
    } else {
        sum /= 2; // 2 subsets
        vector<bool> dp(sum + 1, false); // dp[i]: max sum can reach the number i
        dp[0] = true;
        for (int i = 0; i < size; ++ i) {
            for (int j = sum - n[i]; j >= 0; -- j) { // reverse order for using just one time
                if (dp[j] == true) {
                    dp[j + n[i]] = true;
                }
            }
        }
        cout << dp[sum] << endl;
    }

    return 0;
}