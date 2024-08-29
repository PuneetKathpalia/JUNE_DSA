// Link : https://www.naukri.com/code360/problems/water-supply-in-a-village_1380956
#include<algorithm>
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
}; // Indexing is 0-based

int supplyWater(int n, int k, vector<int> &wells, vector<vector<int>> &pipes) {
    vector<vector<int> > edges; // e[0] -> w, e[1] -> u, e[2] -> v
    for(vector<int> &p : pipes) {
        int u = p[0], v = p[1], w = p[2];
        edges.push_back({w, u, v});
    }
    for(int i = 1; i <= n; ++i) { // Dummy edges : 0 <-> i (wells[i-1])
        edges.push_back({wells[i-1], 0, i});
    }

    sort(edges.begin(), edges.end());

    // Find the MST of the new graph -> n + 1 (0 to n)
    UnionFind dsu(n+1);
    int ans = 0;
    for(vector<int> e : edges) {
        int w = e[0], i = e[1], j = e[2];
        if(!dsu.find(i, j)) {
            dsu.un(i, j);
            ans += w;
        }
    }

    return ans;
}