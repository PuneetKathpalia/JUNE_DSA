#include<bits/stdc++.h>
using namespace std;

#define ps(x,y) fixed<<setprecision(y)<<x


// Link : https://atcoder.jp/contests/dp/tasks/dp_i

long double dp[3000][3000];

int32_t main()
{
	int n; cin >> n;
	dp[0][0] = 1.0;

	for (int i = 1; i <= n; ++i)
	{
		long double pi; cin >> pi;
		for (int j = 0; j <= i; ++j) {
            // Last is tails
			dp[i][j] = dp[i - 1][j] * (1.0 - pi);

            // Last is heads
			if (j)
				dp[i][j] += dp[i - 1][j - 1] * pi;
		}
	}

	long double ans = 0.0;

	for (int i = (n + 1) / 2; i <= n; ++i)
		ans += dp[n][i];

	cout << ps(ans, 10) << '\n';

	return 0;
}