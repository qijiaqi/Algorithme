#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include<algorithm>

using namespace std;

int main () {
    vector<int> n;
    int size, t;
    cin >> size >> t;
    int a;
    for(int i = 0; i < size; ++ i) {
        cin >> a;
        n.push_back(a);
    }

    // BS: Version 1
    int lf = 0;
    int rg = n.size() - 1;
    int md;
    bool find = false;
    while (lf <= rg) {
        md = lf + (rg - lf)/2;
        if (n[md] > t) rg = md - 1;
        else if (n[md] < t) lf = md + 1;
        else {
            cout << md << endl;
            find = true;
            break;
        }
    }
    // BS: Version 2
    lf = 0;
    rg = n.size();
    md = 0;
    while (lf < rg) {
        md = lf + (rg - lf)/2;
        if (n[md] > t) rg = md;
        else if (n[md] < t) lf = md + 1;
        else {
            cout << md << endl;
            find = true;
            break;
        }
    }
    
    if (find == false) cout << -1 << endl;
    return 0;
}