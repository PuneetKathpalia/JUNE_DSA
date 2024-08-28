// https://www.spoj.com/problems/GOODA/

#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, s, e, k;
vector<vector<int> > adj, radj, cgadj;
vector<int> f, f2, comp, dp;

void dfs1(int cur, vector<bool> &vis, vector<int> &order) {
	vis[cur] = true;
	for(int nb : adj[cur]) {
		if(!vis[nb])
			dfs1(nb, vis, order);
	}
	order.push_back(cur);
}

void dfs2(int curNode, int curComp) {
	comp[curNode] = curComp;
	for(int nb : radj[curNode]) {
		if(comp[nb])
			continue;
		dfs2(nb, curComp);
	}
}

void findSCC() {
	vector<bool> vis(n+1);
	vector<int> order;
	for(int i = 1; i <= n; ++i)
		if(!vis[i])
			dfs1(i, vis, order);
		
	reverse(order.begin(), order.end());
	
	comp.resize(n+1);
	int curComp = 1;
	for(int cur : order) {
		if(comp[cur])
			continue;
		dfs2(cur, curComp);
		curComp += 1;
	}
	k = curComp - 1;
}

void makeCG() { // Populate cgadj
	cgadj.resize(k+1);
	for(int i = 1; i <= n; ++i) {
		for(int j : adj[i]) { // i -> j
			if(comp[i] != comp[j])
				cgadj[comp[i]].push_back(comp[j]);
		}
	}
}

int maxFun(int cur) {
	if(dp[cur] != -1)
		return dp[cur];
	
	if(cur == e) {
		return dp[cur] = f2[e];
	}

	dp[cur] = -2; // -2 => Not possible to reach 'e' from cur
	for(int nb : cgadj[cur]) {
		if(maxFun(nb) == -2)
			continue;
		dp[cur] = max(dp[cur], f2[cur] + maxFun(nb));
	}

	return dp[cur];
}

int32_t main() {
	cin >> n >> m >> s >> e;

	adj.resize(n+1), radj.resize(n+1), f.resize(n+1);
	
	for(int i = 1; i <= n; ++i)
		cin >> f[i];

	while(m--) {
		int i, j; cin >> i >> j;
		adj[i].push_back(j);
		radj[j].push_back(i);
	}

	findSCC(); // Finding strongly connected components
	makeCG(); // Make the condensation graph.

	/*
	 k -> Number of SCCs
	 comp[i] -> Index of SCC in which the node is.
	 cgadj -> Adjacency list for the condensation.
	*/

	dp.assign(k+1, -1);
	f2.resize(k+1);
	for(int i = 1; i <= n; ++i) {
		f2[comp[i]] += f[i];
	}

	s = comp[s];
	e = comp[e];
	cout << maxFun(s) << '\n';
	return 0;
}