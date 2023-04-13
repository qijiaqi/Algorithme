#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include<algorithm>

using namespace std;

int main () {
    string s;
    cin >> s;

    // SW
    int i = 0, j = 1, m = 0; // sliding window from index i to j, max length m
    for (; j < s.size() ; ++ j) {
        for (int k = i; k < j ; ++ k) {
            if (s[j] == s[k]) { // change the index i of window if repeat
                i = k + 1;
                break;
            }
        }
        m = max(m, j - i + 1);
    }

    if (s.size() < 2) cout << s.size() << end; 
    else cout << m << endl;
    return 0;
}