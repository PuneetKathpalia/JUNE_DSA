#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int> > &adj, int root = 1) {
    vector<int> par(adj.size());
    
    queue<int> q;
    q.push(root);
    par[root] = -1;

    while(!q.empty()) {
        int cur = q.front();
        cout << cur << ' ';
        q.pop();

        for(int nb : adj[cur]) {
            if(nb == par[cur])
                continue;
            par[nb] = cur;
            q.push(nb);
        }
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

    BFS(adj);
	return 0;
}