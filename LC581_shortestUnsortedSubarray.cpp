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

    // sort
    bool is_s = false;
    if (is_sorted(n.begin(), n.end())) is_s = true;
    vector<int> s(n); 
    // vector<int> s;
    // for (int i : n) s.push_back(i);
    sort(s.begin(), s.end());
    int left = 0, right = size - 1;
    while (s[left] == n[left]) ++ left;
    while (s[right] == n[right]) -- right;
    if (is_s) cout << 0 << endl;
    else cout << right - left + 1 << endl;

    return 0;
}