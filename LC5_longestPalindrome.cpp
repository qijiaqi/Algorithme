#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main () {
    string s;
    cin >> s;
    
    vector< vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
    int max = 0, pos = 0;
    for (int i = s.size() - 1; i >= 0; -- i) { //ordre inverse
        for (int j = i; j < s.size(); ++ j) {
            if (s[i] == s[j]) {    
                if (j - i < 2) dp[i][j] = true; //optimisation
                else if (dp[i+1][j-1]) dp[i][j] = true; //DP
            }
            if (dp[i][j] && max < j-i+1) {
                max = j-i+1;
                pos = i; 
            }
        }
    }
    
    cout << s.substr(pos, max);
    return 0;
}

