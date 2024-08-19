#include<bits/stdc++.h>
using namespace std;


int n, ans = 0;
int w[100001];
vector<int> adj[100001];

void dfs(int i, int par, int mx, int mn)
{
	mx = max(mx, w[i]);
	mn = min(mn, w[i]);

	ans = max({ans, mx - w[i], w[i] - mn});

	for (int ch : adj[i])
		if (ch != par)
			dfs(ch, i, mx, mn);
}

int main()
{
	cin >> n;
	int root;

	for (int i = 1; i <= n; ++i)
		cin >> w[i];

	for (int i = 1; i <= n; ++i)
	{
		int pi; cin >> pi;

		if (pi == -1)
			root = i;

		else
			adj[i].push_back(pi), adj[pi].push_back(i);
	}

	dfs(root, 0, INT_MIN, INT_MAX);

	cout << ans << '\n';
	return 0;
}