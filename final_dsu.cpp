#include <bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    int *pr;
    int *sz;
    int numComp;

    UnionFind(int n) {
        pr = new int[n + 1];
        sz = new int[n + 1];
        numComp = n;

        for (int i = 1; i <= n; ++i)
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
}; //default indexing is 1-based

int main() {
    int n; cin >> n;
	UnionFind dsu(n);
    dsu.un(1, 2);
    cout << dsu.find(1, 2) << '\n';
    cout << dsu.find(2, 3) << '\n';
    dsu.un(1, 3);
    cout << dsu.find(2, 3) << '\n';
	return 0;
}