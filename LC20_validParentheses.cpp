#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include<algorithm>

using namespace std;

int main () {
    string s;
    cin >> s;

    // Stack
    stack<char> st;
    for (char c : s) {
        if (c == '[') st.push(']');
        else if (c == '(') st.push(')');
        else if (c == '{') st.push('}');
        else if (st.empty() || st.top() != c) {
            cout << false << endl;
            return 0;
        } else st.pop();
    }

    cout << st.empty() << endl;
    return 0;
}