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

    vector<vector<int>> res;
    sort(n.begin(), n.end()); // sort
    for (int i = 0; i < size; ++ i) {
        if (i > 0 && n[i] == n[i - 1]) continue; // skip repeat number
        int left = i + 1, right = size - 1;
        while (left < right) {
            if (n[i]+n[left]+n[right] < 0) {
                ++ left;
                while (right > left && n[left] == n[left - 1]) ++ left; // skip repeat number
            } else if (n[i]+n[left]+n[right] > 0) {
                -- right;
                while (right > left && n[right] == n[right + 1]) -- right; // skip repeat number
            } else {
                ++ left;
                -- right;
                res.push_back({n[i], n[left], n[right]});
                while (right > left && n[left] == n[left - 1]) ++ left; // skip repeat number
                while (right > left && n[right] == n[right + 1]) -- right; // skip repeat number
            }
        }
    }

    for (int i = 0; i < res.size(); ++ i) {
        for (int j = 0; j < res[i].size(); ++ j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}