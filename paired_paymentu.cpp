// Link : https://codeforces.com/contest/1486/problem/E

#include<bits/stdc++.h>
using namespace std;

#define inf 1e9

int main()
{
	int n, m; cin >> n >> m;

	vector<vector<pair<int,int> > > adj(n + 1);

	while (m--)
	{
		int i, j, k; cin >> i >> j >> k;
		adj[i].push_back({j, k});
		adj[j].push_back({i, k});
	}

	vector<vector<int> > d(n + 1, vector<int> (51, inf));
	set<vector<int> > s;
	s.insert({0, 1, 0});
	d[1][0] = 0;

	while (!s.empty())
	{
		auto it = s.begin();
		int cur = (*it)[0], i = (*it)[1], j = (*it)[2];
		s.erase(it);

		for (auto &e : adj[i])
		{
			int to = e.first, w = e.second;

			if (!j)
			{
				if (cur < d[to][w])
				{
					s.erase({d[to][w], to, w});
					d[to][w] = cur;
					s.insert({d[to][w], to, w});
				}
			}

			else
			{
				int add = (j + w) * (j + w);
				if (cur + add < d[to][0])
				{
					s.erase({d[to][0], to, 0});
					d[to][0] = cur + add;
					s.insert({d[to][0], to, 0});
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i)
		if (d[i][0] != inf)
			cout << d[i][0] << ' ';
		else
			cout << -1 << ' ';

	cout << '\n';
	return 0;
}