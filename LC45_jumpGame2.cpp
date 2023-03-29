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

    // suppose we can always reach the last element
    int cur = 0, next = 0, min = 0;
    for (int i = 0; i < size - 1; ++ i) { 
        next = max(next, n[i] + i); // calculate the new bound if we jump
        if (i == cur) { // reach the longest index with current min 
            cur = next;
            ++ min;
        }
    }

    cout << min << endl;
    return 0;
}