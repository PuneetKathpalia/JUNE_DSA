// Link : https://codeforces.com/contest/1272/problem/E

#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj, int n, vector<int> src) {
	queue<int> q;
	vector<int> d(n, -1);

	/*for (int i = 0; i < n; ++i)
		cout << d[i] << ' ';
	cout << '\n';*/

	for (auto s : src)
	{
		q.push(s);
		d[s] = 0;
	}

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : adj[v]) {
			if (d[u] == -1) {
				q.push(u);
				d[u] = d[v] + 1;
			}
		}
	}

	return d;
}

int main()
{
	int n; cin >> n;
	vector<vector<int>> adj(n);

	vector<int> odd, ev;

	for (int i = 0; i < n; ++i)
	{
		int x; cin >> x;

		if (x & 1)
			odd.push_back(i);
		else
			ev.push_back(i);

		if (i - x >= 0)
			adj[i - x].push_back(i);

		if (i + x < n)
			adj[i + x].push_back(i);
	}

	vector<int> ans(n);

	vector<int> ds = bfs(adj, n, odd);

	for (auto id : ev)
		ans[id] = ds[id];

	/*for (int i = 0; i < n; ++i)
		cout << ds[i] << ' ';
	cout << '\n';*/

	ds = bfs(adj, n, ev);

	for (auto id : odd)
		ans[id] = ds[id];

	for (int i = 0; i < n; ++i)
		cout << ans[i] << ' ';
	return 0;
}