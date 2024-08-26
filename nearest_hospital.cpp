#include <bits/stdc++.h>
using namespace std;

#define inf 1e9

int n;
vector<vector<vector<int> > > adj;

vector<int> multiDijkstra(vector<int> sources) {
    vector<int> d(n+1, inf);
    priority_queue <pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > > q;

    for(int src : sources) {
        d[src] = 0;
        q.push({0, src}); // [dist, node]
    }

    while(!q.empty()) {
        int cur = q.top().second;
        int curD = q.top().first;

        q.pop();
        
        if(curD != d[cur])
            continue;
        
        for(vector<int> e : adj[cur]) {
            int nb = e[0];
            int w = e[1];
            if(d[nb] > d[cur] + w) {
                d[nb] = d[cur] + w;
                q.push({d[nb], nb});
            }
        }
    }

    for(int i = 1; i <= n; ++i)
        if(d[i] == inf)
            d[i] = -1;
        
    return d;
}

int main() {
    int m; cin >> n >> m;
    adj.resize(n+1);

    while(m--) {
        int u, v, w; cin >> u >> v >> w;
        vector<int> edge;
        edge.push_back(u); // edge[0] = node
        edge.push_back(w); // edge[1] = weight

        // Reverse Graph
        adj[v].push_back(edge);
    }

    int numHospitals; cin >> numHospitals;
    vector<int> hospitals;

    while(numHospitals--) {
        int h; cin >> h;
        hospitals.push_back(h);
    }

    vector<int> ans = multiDijkstra(hospitals);
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
	return 0;
}