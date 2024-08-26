// Link : https://www.codechef.com/problems/BESTPATH

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e15
#define vi vector<int>

int n, m;
vector<vi> edges;

vi bellmanFord() {
	vi d(n + 1);

	for (int i = 0; i < 2 * n; ++i) {
		for (vi &e : edges) {
			int u = e[0], v = e[1], w = e[2];

			if (i < n - 1)
				d[v] = min(d[v], d[u] + w);

			else {
				//i >= n
				if (d[v] > d[u] + w)
					d[v] = -inf;
			}
		}
	}
	return d;
}

int32_t main()
{
    int t; cin >> t;
	while(t--) {
		cin >> n >> m;
		edges.clear();

		for (int i = 0; i < m; ++i) {
			int u, v, w; cin >> u >> v >> w;
			edges.push_back({u, v, w});
		}

		vi en = bellmanFord();

		for (vi &v : edges)
			swap(v[0], v[1]);

		vi st = bellmanFord();

		for (int i = 1; i <= n; ++i)
		{
			if (st[i] == -inf or en[i] == -inf)
				cout << "INF\n";

			else
				cout << st[i] + en[i] << '\n';
		}
	}

	return 0;
}