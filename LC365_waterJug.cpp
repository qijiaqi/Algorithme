#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int gcd_BF(int a, int b) {
    int r;
    while (a%b!=0)
    {
        r=a%b;
        a=b;
        b=r;    
    }
    return b; 
}

int gcd_RE(int a, int b) {
    if(a%b==0) return b;
    else return gcd_RE(b,a%b);
}

int gcd(int c1, int c2) {
    return c2 > 0 ? gcd (c2, c1 % c2) : c1;
}

int main () {
    int c1, c2, t;
    cin >> c1 >> c2 >> t;

    bool res = false;
    // Bézout
    // Every opration can change c1 or c2 value of the sum of two jugs
    // c1*x + c2*y = t has solution if t%gcd(c1, c2)
    if (t > c1 + c2) cout << res << endl;
    else cout << (t % gcd(c1, c2) == 0) << endl;
    
    // DFS : TIMEOUT !
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