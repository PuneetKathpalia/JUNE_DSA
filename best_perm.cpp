#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    // arr = [0, 1, 2, 3, .... n-1];

    vector<vector<int> > rew(n, vector<int>(n));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> rew[i][j];
    
    vector<int> dp(1<<n);

    for(int m = 1; m < (1<<n); ++m) {
        for(int i = 0; i < n; ++i) {
            if((m>>i)&1)
                dp[m] = max(dp[m], dp[m ^ (1<<i)] + rew[i][__builtin_popcount(m) - 1]);
        }
    }

    cout << dp[(1<<n) - 1] << '\n';
	return 0;
}
