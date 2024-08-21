#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<pair<int,int> > > adj;

vector<int> bfs01(int src) {
	vector<int> d(n + 1, INT_MAX);
	d[src] = 0;
	deque<int> q;
	q.push_front(src);

	while (!q.empty()) {
		int cur = q.front();
		q.pop_front();
		for (auto edge : adj[cur]) {
			int nb = edge.first;
			int w = edge.second;
			if (d[cur] + w < d[nb]) {
				d[nb] = d[cur] + w;
				if (w == 1)
					q.push_back(nb);
				else
					q.push_front(nb);
			}
		}
	}

	for(int i = 1; i <= n; ++i)
		if(d[i] == INT_MAX)
			d[i] = -1;

	return d;
}

int main() {
	int m; cin >> n >> m;

	adj.resize(n + 1);

	while (m--) {
		int i, j, w; cin >> i >> j >> w;

		adj[i].push_back({j, w});
		adj[j].push_back({i, w});
	}

	vector<int> d = bfs01(1);

	for(int i = 1; i <= n; ++i) {
		cout << i << ' ' << d[i] << '\n';
	}

	return 0;
}