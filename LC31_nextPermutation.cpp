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

    int i = size - 1, j = size - 1;
    while (i > 0 && n[i - 1] >= n[i]) -- i; // 13542, n[i - 1] = 3
    if (i == 0) sort(n.begin(), n.end()); // 54321 => 12345
    else {
        while (n[i - 1] >= n[j]) -- j;
        swap(n[i - 1], n[j]); // 14532
        reverse(n.begin() + i, n.end()); // 14235
    }

    for(int i = 0; i < size; ++ i) {
        cout << n[i] << " "; 
    } 
    cout << endl;
    return 0;
}