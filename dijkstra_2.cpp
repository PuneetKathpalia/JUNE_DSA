#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e18;

int n;
vector<vector<pair<int,int>>> adj;

vector<int> dijkstra(int src) {
    vector<long long> d(n+1,inf);
    vector<int> par(n+1, -1);
    d[src] = 0;

    // Set on unmarked nodes (and their distance)
    priority_queue <pair<long long,int> , vector<pair<long long,int> >, greater<pair<long long,int> > > q;
    q.push({d[src], src});
    
    while(!q.empty()) {
        int cur = q.top().second; // shortest distance vali unmarked node
        long long curDist = q.top().first; // dist of cur node
        q.pop(); // Mark the 'cur' node

        if(curDist != d[cur])
            continue;
        
        // Relaxation on neighbors
        for(pair<int,int> e : adj[cur]) {
            int nb = e.first;
            int w = e.second;
            if(d[cur] + w < d[nb]) {
                d[nb] = d[cur] + w; // Update it.
                par[nb] = cur;
                q.push({d[nb], nb}); // Insert the new one.
            }
        }
    }

    for(long long &val : d)
        if(val == inf)
            val = -1;
    
    return par;
}

int main() {
    int m; cin >> n >> m;
    adj.resize(n+1);
   
    while(m--) {
        int i, j, w; cin >> i >> j >> w;
        adj[i].push_back({j, w});
        adj[j].push_back({i, w});
    }

    vector<int> par = dijkstra(1);

    if(par[n] == -1) {
        cout << -1 << '\n';
    }
    else {
        vector<int> ans;
        int cur = n;
        while(cur != -1) {
            ans.push_back(cur);
            cur = par[cur];
        }
        reverse(ans.begin(), ans.end());
        for(int node : ans)
            cout << node << ' ';
    }

	return 0;
}