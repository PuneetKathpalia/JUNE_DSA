#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int> > &adj, int cur = 1, int par = -1) {
    cout << cur << ' ';
    for(int neighb : adj[cur]) {
        if(neighb == par)
            continue;
        DFS(adj, neighb, cur);
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
	return 0;
}