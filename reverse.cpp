// Link : https://www.codechef.com/AUG14/problems/REVERSE
// Note : Submitting is not allowed for this problem anymore.

#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<pair<int,int> > > adj;

int bfs01() {
	vector<int> d(n + 1, INT_MAX);
	d[1] = 0;
	deque<int> q;
	q.push_front(1);

	while (!q.empty())
	{
		int v = q.front();
		q.pop_front();
		for (auto edge : adj[v]) {
			int u = edge.first;
			int w = edge.second;
			if (d[v] + w < d[u]) {
				d[u] = d[v] + w;
				if (w == 1)
					q.push_back(u);
				else
					q.push_front(u);
			}
		}
	}

	return d[n] == INT_MAX ? -1 : d[n];
}

int main()
{
	int m; cin >> n >> m;

	adj.resize(n + 1);

	while (m--) {
		int i, j; cin >> i >> j;

		adj[i].push_back({j, 0});
		adj[j].push_back({i, 1});
	}

	cout << bfs01() << '\n';

	return 0;
}