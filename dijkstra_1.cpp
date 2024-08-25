// Link : https://leetcode.com/problems/network-delay-time/

class Edge {
    public:
    int node;
    int weight;
    Edge(int n, int w) {
        node = n;
        weight = w;
    }
};

class Solution {
    const int inf = 1e9;
    int n;
    vector<vector<Edge> > adj;
    vector<int> dijkstra(int src) {
        vector<int> d(n+1, inf);
        vector<bool> mark(n+1);

        d[src] = 0;

        for(int iter = 0; iter < n; ++iter) {
            // Get the smallest distance vali unmarked node.
            int cur = -1, dist = inf;
            for(int i = 1; i <= n; ++i) {
                if(mark[i] == false && d[i] <= dist)
                    cur = i, dist = d[i];
            }

            mark[cur] = true; // Mark it

            // Relaxation of cur's neighbors
            for(Edge e : adj[cur]) {
                int nb = e.node;
                int w = e.weight;
                d[nb] = min(d[nb], d[cur] + w);
            }
        }

        // Replace inf values with -1;
        for(int & val : d)
            if(val == inf)
                val = -1;
        
        return d;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        this->n = n;
        adj.resize(n+1);

        for(vector<int> e : times) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            Edge ed(v, w);
            adj[u].push_back(ed);
        }

        int ans = -1;
        vector<int> d = dijkstra(k);

        for(int i = 1; i <= n; ++i) {
            if(d[i] == -1)
                return -1;
            ans = max(ans, d[i]);
        }

        return ans;
    }
};