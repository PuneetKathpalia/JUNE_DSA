#include <bits/stdc++.h>
using namespace std;

int maxRewards(vector<vector<int>> &rew, int n) {
    vector<vector<int>> dp(n, vector<int>(n)), pre(n, vector<int>(n)), suf(n, vector<int>(n));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i == 0)
                dp[i][j] = rew[i][j];
            else {
                int comingFromLeft = rew[i][j] - j + pre[i-1][j]; // dp[i-1][k] + k;
                int comingFromRight = rew[i][j] + j + suf[i-1][j]; // dp[i-1][k] - k;
                dp[i][j] = max(comingFromLeft, comingFromRight);
            }
            pre[i][j] = j == 0? dp[i][j] + j : max(pre[i][j-1], dp[i][j] + j);
        }
        for(int j = n - 1; j >= 0; --j)
            suf[i][j] = j == n - 1? dp[i][j] - j : max(suf[i][j+1], dp[i][j] - j);
    }

    int ans = 0;
    for(int j = 0; j < n; ++j)
        ans = max(ans, dp[n-1][j]);
    return ans;
}

int main() {
    int n, c; cin >> n;
    vector<vector<int>> rew(n, vector<int>(n));

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> rew[i][j];

    cout << maxRewards(rew, n) << '\n';
	return 0;
}
