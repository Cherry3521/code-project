#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int dp[1000][1000];

int lcs(int i, int j, string &s1, string &s2) {
    if(i == s1.length() || j == s2.length())
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(s1[i] == s2[j])
        return dp[i][j] = 1 + lcs(i+1, j+1, s1, s2);

    return dp[i][j] = max(lcs(i+1, j, s1, s2),
                          lcs(i, j+1, s1, s2));
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    memset(dp, -1, sizeof(dp));

    cout << lcs(0, 0, s1, s2) << endl;

    return 0;
}
