#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 998244353

// Link : https://codeforces.com/contest/1312/problem/D

int pwmd(int a, int n)
{
	if (!n)
		return 1;
	int pt = pwmd(a, n / 2);
	pt *= pt, pt %= mod;
	if (n & 1)
		pt *= a, pt %= mod;
	return pt;
}

int fct[200001];

int nCr(int n, int r)
{
	int ans = fct[n];

	ans = (ans * pwmd(fct[r], mod - 2)) % mod;
	ans = (ans * pwmd(fct[n - r], mod - 2)) % mod;

	return ans;
}

int32_t main()
{
	fct[0] = 1;

	for (int i = 1; i <= 200000; ++i)
		fct[i] = (fct[i - 1] * i) % mod;

	int n, m; cin >> n >> m;

	//mCn-1*(n-2)*2^(n-3);

	int ans = nCr(m, n - 1);
	ans = (ans * (n - 2)) % mod;

	if (n >= 3)
		ans = (ans * pwmd(2, n - 3)) % mod;

	cout << ans << '\n';

	return 0;
}