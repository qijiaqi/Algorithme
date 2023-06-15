#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <bits/stdc++.h>
#include<algorithm>

using namespace std;

int main () {
    int c1, c2, t;
    cin >> c1 >> c2 >> t;

    // DFS : TIMEOUT !
    bool res = false;
    // current state of two jugs
    stack<pair<int, int>> st;
    st.push({0, 0});
    // check if state already exist
    struct hashFunction {
    size_t operator()(const pair<bool, bool> &x) const
        {
            return x.first ^ x.second;
        }
    };
    unordered_set<pair<int, int>, hashFunction> set;
    while(!st.empty()) {
        pair<int, int> cur = st.top();
        //cout<<cur.first<<" "<<cur.second<<endl;
        st.pop();
        // true if find
        if (cur.first == t || cur.second == t || cur.first + cur.second == t) {
            res = true;
            break;
        }
        // pass if exist
        if (set.find(cur) != set.end()) continue;
        set.insert(cur);
        // All possible situation
        st.push({0, cur.second});
        st.push({cur.first, 0});
        st.push({c1, cur.second});
        st.push({cur.first, c2});
        if (cur.first + cur.second > c1) st.push({c1, cur.second - c1 + cur.first});
        else st.push({cur.first + cur.second, 0});
        if (cur.first + cur.second > c2) st.push({cur.first - c2 + cur.second, c2});
        else st.push({0, cur.first + cur.second});
        //cout<<set.size()<<" "<<st.size()<<endl;
        }

        cout << res << endl;
        return 0;
}