#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include<algorithm>

using namespace std;

int main () {
    vector<int> n, m;
    int size;
    cin >> size;
    int a;
    for(int i = 0; i < size; ++ i) {
        cin >> a;
        n.push_back(a);
        m.push_back(a);
    }
    // special case:
    int i;
    for (i = size - 1; i >= 0; -- i) {
        if (n[i] == 9) n[i] = 0; // carry only for 9
        else { // no carry => stop and add one
            ++ n[i];
            break;
        }
    }
    // only has 9 in the array
    if (i == -1 && n[0] == 0) n.insert(n.begin(), 1);
    
    for (int nb : n) cout << nb;
    cout << endl;

    // general case: 
    int c = 0;
    m[size - 1] += 1;
    if (m[size - 1] >= 10) c = 1;
    m[size - 1] %= 10;
    // stop if on carry
    for (int j = size - 2; j >= 0 && c == 1; -- j) {
        m[j] += c;
        // compute carry
        if (m[j] >= 10) c = 1;
        else c = 0;
        m[j] %= 10;
    }
    // only has 9 in the array
    if (c == 1) m.insert(m.begin(), 1);

    for (int nb : m) cout << nb;
    cout << endl;
    return 0;
}