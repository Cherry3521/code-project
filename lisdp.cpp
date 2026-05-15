#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int dp[1000][1000];

int LIS(int i, int prev, vector<int> &nums) {
    if(i == nums.size()) return 0;

    if(dp[i][prev+1] != -1)
        return dp[i][prev+1];

    int skip = LIS(i+1, prev, nums);

    int take = 0;
    if(prev == -1 || nums[i] > nums[prev])
        take = 1 + LIS(i+1, i, nums);

    return dp[i][prev+1] = max(skip, take);
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << LIS(0, -1, nums) << endl;

    return 0;
}
