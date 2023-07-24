#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <stdint.h>
#include<algorithm>

using namespace std;

int dfs (int x, int y, int z, int pre) {
    // AA
    if (pre == 1) {
        if (y == 0) return 0;
        return dfs(x, y-1, z, 2) + 2;
    }
    // BB || AB
    if (x == 0 && z == 0) return 0;
    if (x == 0) return dfs(x, y, z-1, 3) + 2;
    if (z == 0) return dfs(x-1, y, z, 1) + 2;
    return max(dfs(x, y, z-1, 3), dfs(x-1, y, z, 1)) + 2;
}

int main () {
    int x, y, z;
    cin >> x >> y >> z;

    // Math : (BB)AABB*(AA)+AB*
    cout << 2*(2*min(x, y) + z + (x!=y)) << endl;
    // DFS : AB+ impossible && Time Out!
    cout << max(dfs(x, y, z, 1), dfs(x, y, z, 2)) << endl;
    // MS :
}