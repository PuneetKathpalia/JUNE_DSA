#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

// Link : https://codeforces.com/problemset/problem/1105/C

int32_t main()
{
	int n,l,r; cin >> n >> l >> r;
	int zero = r/3 - (l-1)/3;
	int one = l > 1 ? (r-1)/3 - (l-2)/3 : 1 + (r-1)/3;
	int two = (r - l + 1) - zero - one;
	int dp[200001][3];
	
	dp[1][0] = zero;
	dp[1][1] = one;
	dp[1][2] = two;
	
	for(int i = 2; i <= n; ++i) {
		for(int j = 0; j <= 2; ++j) {
			// 1st number is a multiple of 3.
			long poss1 = (zeroCnt * dp[i-1][j]) % mod;

			// 1st number % 3 => 1
			long poss2 = (oneCnt * dp[i-1][(j+2)%3]) % mod;

			// 1st number % 3 => 2
			long poss3 = (twoCnt * dp[i-1][(j+1)%3]) % mod;

			dp[i][j] = (poss1 + poss2 + poss3) % mod;
		}
	}

	cout<<dp[n][0]<<'\n';
	return 0;
} 