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
    vector<int> up(size, 1), down(size, 1); // longest length 
    // end with one of the elements in n[i]...n[0]
    for (int i = 1; i < size; ++ i) {
        if (n[i] > n[i - 1]) { // renew up
            up[i] = max(up[i - 1], down[i - 1] + 1);
            down[i] = down[i - 1];
        } else if (n[i] < n[i - 1]) { // renew down
            up[i] = up[i - 1];
            down[i] = max(down[i - 1], up[i - 1] + 1);
        } else { //stay
            up[i] = up[i - 1];
            down[i] = down[i - 1];
        }
    }
    // DP +
    int u = 1, d = 1;
    for (int i = 1; i < size; ++ i) {
        if (n[i] > n[i - 1]) u = max(u, d + 1);
        else if (n[i] < n[i - 1]) d = max(d, u + 1);
    }
    // GR
    int pre = 0, cur = 0, mx = 1;
    for (int i = 0; i < size - 1; ++ i) {
        cur = n[i + 1] - n[i];
        if ((pre <= 0 && cur > 0) || (pre >= 0 && cur < 0)) { 
        // just focus on trends, the size isn't important 
        //If it changes, add it.  
            ++ mx;
            pre = cur;
        }
    }

    //cout << max(up[size - 1], down[size - 1]) << endl;
    cout << max(u, d) << " " << mx << endl;
    return 0;
} 