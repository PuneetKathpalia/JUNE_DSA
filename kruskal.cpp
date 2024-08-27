// Article : https://cp-algorithms.com/graph/mst_kruskal_with_dsu.html
// Link : https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

class UnionFind {
public:
    int *pr;
    int *sz;
    int numComp;

    UnionFind(int n) {
        pr = new int[n];
        sz = new int[n];
        numComp = n;

        for (int i = 0; i < n; ++i)
            pr[i] = i, sz[i] = 1;
    }

    int root(int i) {
        if (pr[i] == i)
            return i;

        return pr[i] = root(pr[pr[i]]);
    }

    int find(int i, int j) {
        return (root(i) == root(j));
    }

    int un(int i, int j) {
        int u = root(i);
        int v = root(j);

        if (u == v)
            return 0;

        if (sz[u] < sz[v])
            swap(u, v);

        pr[v] = u;
        sz[u] += sz[v];
        numComp -= 1;
        return 1;
    }
}; // indexing is 0-based

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[]) {
        vector<vector<int>> edges; // e[0] -> w, e[1] -> u, e[2] -> v
        for(int i = 0; i < n; ++i) {
            for(vector<int> e : adj[i]) {
                int j = e[0], w = e[1];
                if(i < j) {
                    edges.push_back({w, i, j});
                }
            }
        }
        sort(edges.begin(), edges.end());
        UnionFind dsu(n);
        int minCost = 0;
        for(vector<int> e : edges) {
            int w = e[0], i = e[1], j = e[2];
            if(!dsu.find(i, j)) {
                dsu.un(i, j);
                minCost += w;
            }
        }
        return minCost;
    }
};