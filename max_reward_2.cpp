#include <bits/stdc++.h>
using namespace std;

int maxRewards(vector<vector<int>> &rew, int n, int c) {
    vector<vector<int>> dp(n, vector<int>(n));

    int lastMax = INT_MIN, lastSecMax = INT_MIN;
    for(int i = 0; i < n; ++i) {
        int curMax = INT_MIN, curSecMax = INT_MIN;
        for(int j = 0; j < n; ++j) {
            if(i == 0)
                dp[i][j] = rew[i][j];
            else {
                int maxFromDiffCity = dp[i-1][j] == lastMax? lastSecMax : lastMax;
                dp[i][j] = rew[i][j] + max(dp[i-1][j], maxFromDiffCity - c);
            }

            if(dp[i][j] >= curMax)
                curSecMax = curMax, curMax = dp[i][j];
            else if(dp[i][j] >= curSecMax)
                curSecMax = dp[i][j];
        }

        // After everything done
        lastSecMax = curSecMax;
        lastMax = curMax;
    }

    int ans = 0;
    for(int j = 0; j < n; ++j)
        ans = max(ans, dp[n-1][j]);
    return ans;
}

int main() {
    int n, c; cin >> n >> c;
    vector<vector<int>> rew(n, vector<int>(n));

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> rew[i][j];

    cout << maxRewards(rew, n, c) << '\n';
	return 0;
}
