#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include<algorithm>

using namespace std;

int main () {
    string a, b;
    cin >> a >> b;
    // getline(cin, a, '\n');
    // cout << a << " " << b << endl;

    // carry order
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    // index & carry
    int i = 0, c = 0;
    string res;
    while (i < max(a.size(), b.size())) {
        // chat to int
        int x = 0, y = 0;
        if (i < a.size()) x = a[i] - '0';
        if (i < b.size()) y = b[i] - '0';
        // XOR ^ to compute binary number
        if (x^y^c == 1) res.push_back('1');
        else res.push_back('0');
        // compute carry
        if (x + y + c > 1) c = 1;
        else c = 0;
        ++ i;
    }
    if (c == 1) res.push_back('1');
    reverse(res.begin(), res.end());

    cout << res << endl;
    return 0;
}