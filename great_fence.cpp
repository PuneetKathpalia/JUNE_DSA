#include <bits/stdc++.h>
using namespace std;

// Link : https://codeforces.com/contest/1221/problem/D

long long getMinCost(vector<int> &a, vector<int> &b, vector<vector<long long> > &dp, int i, int j) {
    if(i >= a.size()) // base case
        return 0;

    if(i >= a.size() - 1) // last index
        return j*b[i];
    
    if(dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = LLONG_MAX;

    for(int k = 0; k <= 2; ++k) {
        if(a[i] + j == a[i+1] + k)
            continue;
        dp[i][j] = min(dp[i][j], j*b[i] + getMinCost(a, b, dp, i+1, k));
    }

    return dp[i][j];
}

int main() {
	int q; cin >> q;
    while(q--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        
        for(int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }

        // dp[i][j] = ans for fences[i ... n - 1] s.t. the height
        // of the ith fence is incremented exactly by j units.
        vector<vector<long long> > dp(n, vector<long long>(3, -1));

        long long ans = LLONG_MAX;
        for(int j = 0; j <= 2; ++j)
            ans = min(ans, getMinCost(a, b, dp, 0, j));
        cout << ans << '\n';
    }
	return 0;
}