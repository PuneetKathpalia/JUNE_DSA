#include<bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e15
#define vi vector<int>

int n, m;
vector<vi> edges;

vi bellmanFord(int src) {
	vi d(n + 1, inf);

	d[src] = 0;

	for (int i = 1; i <= 2 * n; ++i) {
		for (vi &e : edges) {
			int u = e[0], v = e[1], w = e[2];

			if (i <= n - 1)
				d[v] = min(d[v], d[u] + w);

			else { //i >= n
				if (d[v] > d[u] + w)
					d[v] = -inf;
			}
		}
	}
	return d;
}

int32_t main() {
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		edges.push_back({u, v, w});
	}

	int src; cin >> src;

	vi d = bellmanFord(src);

	for(int i = 1; i <= n; ++i) {
		if(d[i] == inf)
			cout << "INF\n";
		else if(d[i] == -inf)
			cout << "-INF\n";
		else
			cout << d[i] << '\n';
	}
	return 0;
}