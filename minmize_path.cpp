#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int> > > adj;
int n;

bool isReachable(int src, int dest, int threshold)
{
	queue<int> q;
	vector<int> dis(n + 1, -1);

	q.push(src);
	dis[src] = 0;

	while (!q.empty())
	{
		int i = q.front();
		q.pop();

		if(i == dest)
            return true;

		for (pair<int,int>  nb : adj[i])
		{
			if (dis[nb.first] != -1 or nb.second > threshold)
				continue;

			q.push(nb.first);
			dis[nb.first] = dis[i] + 1;
		}
	}

	return false;
}

int main()
{
	int m; cin >> n >> m;
	adj.resize(n + 1);

	while (m--)
	{
		int i, j, w; cin >> i >> j >> w;
		adj[i].push_back({j, w});
		adj[j].push_back({i, w});
	}

	int src, dest; cin >> src >> dest;

	int beg = 1, end = INT_MAX, ans = -1;

    while(beg <= end) {
        int mid = (beg + end)/2;
        if(isReachable(src, dest, mid))
            ans = mid, end = mid - 1;
        else
            beg = mid + 1;
    }

    cout << ans << '\n';

	return 0;
}