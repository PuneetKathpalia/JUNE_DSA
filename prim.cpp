// Article : https://cp-algorithms.com/graph/mst_prim.html
// Link : https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

class Solution
{
    const int inf = 1e9;
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[]) {
        vector<int> minw(n, inf);
        vector<bool> done(n, false);
        int minCost = 0;
        set<pair<int,int> > s;
        
        s.insert({0, 0}), minw[0] = 0;
        while(!s.empty()) {
            int cur = s.begin()->second;
            s.erase(s.begin());
            minCost += minw[cur];
            done[cur] = true;
            for(vector<int> e : adj[cur]) {
                int nb = e[0], w = e[1];
                if(!done[nb] and w < minw[nb]) {
                    s.erase({minw[nb],nb});
                    minw[nb] = w;
                    s.insert({minw[nb],nb});
                }
            }
        }
        
        return minCost;
    }
};