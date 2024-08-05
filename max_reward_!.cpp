#include <bits/stdc++.h>
using namespace std;

int maxRewards(vector<vector<int>> &rew, int n) {
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        int bestReward = 0;
        for(int j = 0; j < n; ++j)
            bestReward = max(bestReward, rew[i][j]);
        ans += bestReward;
    }
    return ans;
}

int main() {
    int n; cin >> n;
    vector<vector<int>> rew(n, vector<int>(n));

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> rew[i][j];

    cout << maxRewards(rew, n) << '\n';
	return 0;
}