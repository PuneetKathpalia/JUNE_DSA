#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;
int n;

void dfs(int cur, vector<int> &par) {
    // cout << cur << ' ';
    for(int nb : adj[cur]) {
        if(par[nb] != -1)
            continue;
        par[nb] = cur;
        dfs(nb, par);
    }
}

vector<int> printLexicoSmallest(int src, int dest) {
    for(int i = 1; i <= n; ++i)
        sort(adj[i].begin(), adj[i].end());
    
    vector<int> par(n+1,-1);
    par[src] = src;
    dfs(src, par);

    vector<int> ans;
    if(par[dest] == -1)
        ans.push_back(-1);
    
    else {
        int cur = dest;
        while(cur != src) {
			ans.push_back(cur);
			cur = par[cur];
		}
        ans.push_back(src);
        reverse(ans.begin(), ans.end());
    }

    return ans;
}

int main() {
	int m; cin >> n >> m;
	adj.resize(n + 1);

	while (m--)
	{
		int i, j; cin >> i >> j;
		adj[i].push_back(j);
		adj[j].push_back(i);
	}

    int src, dest; cin >> src >> dest;

	vector<int> ans = printLexicoSmallest(src, dest);

    for(int cur : ans)
        cout << cur << ' ';

	return 0;
}