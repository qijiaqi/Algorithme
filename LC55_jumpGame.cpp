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

    int cover = 0;// largest index can be covered
    bool b = 0;
    for (int i = 0; i <= cover; ++ i) { //dynamique
        cover = max(cover, n[i] + i);
        if (cover >= size - 1) b = 1;
    }

    if (b) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}