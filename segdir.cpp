// Link : https://www.codechef.com/ICPCIN19/problems/SEGDIR

#include<bits/stdc++.h>
using namespace std;

int l[1001], r[1001], v[1001];
vector<int> adj[1001];
int dir[1001];

bool dfs(int node) {
	for (auto el : adj[node]) {
		int req = (1 + 2) - dir[node];

		if (dir[el] != 0) { // already visited
			if (dir[el] == req)
				continue;

			else {
				return false;
			}
		}

		else {
			dir[el] = req;
			bool can = dfs(el);
            if(!can)
                return false;
		}
	}
    return true;
}

bool common(int i, int j) {

	int lv = max(l[i], l[j]);
	int rv = min(r[i], r[j]);

	return (lv <= rv);
}

int32_t main()
{
	int t; cin >> t;

	while (t--)
	{
		int n; cin >> n;

		for (int i = 1; i <= n; ++i)
			cin >> l[i] >> r[i] >> v[i];

		for (int i = 1; i <= n; ++i)
			adj[i].clear();

		for (int i = 1; i <= n; ++i)
			for (int j = i + 1; j <= n; ++j)
			{
				if (v[i] == v[j] && common(i, j))
					adj[i].push_back(j), adj[j].push_back(i);
			}

		//We have our graph
		memset(dir, 0, sizeof(dir));
        bool can = true;
		for (int i = 1; i <= n; ++i)
		{
			if (dir[i])
				continue;

			dir[i] = 1;

			can = can && dfs(i);
		}

		if (can)
			cout << "YES\n";

		else
			cout << "NO\n";

	}
	return 0;
}