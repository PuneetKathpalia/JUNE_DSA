#include <bits/stdc++.h>
using namespace std;

int num[1000001], level[1000001];

void DFS(vector<vector<int> > &adj, int cur = 1, int par = -1) {
    level[cur] = par == -1? 0 : level[par] + 1; // before the DFS calls
    num[cur] = 1;
    for(int neighb : adj[cur]) {
        if(neighb == par)
            continue;
        DFS(adj, neighb, cur);
        num[cur] += num[neighb];
    }
}

int main() {
    int n; cin >> n;
    vector<vector<int> > adj(n + 1);

    for(int e = 0; e < n - 1; ++e) { // n - 1 edges
        int i, j; cin >> i >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    } // Here, we have the adjacency list.

    DFS(adj);

    // for(int i = 1; i <= n; ++i)
    //     cout << i << ' ' << num[i] << '\n';

    for(int i = 1; i <= n; ++i)
        cout << i << ' ' << level[i] << '\n';
    
	return 0;
}