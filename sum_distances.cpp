// Link : https://leetcode.com/problems/sum-of-distances-in-tree/
// Editorial : https://www.youtube.com/live/G7xuHkYuU_8?si=DbarFxhRUh2q89ZZ&t=785

class Solution {
    vector<int> ans, num, up, down;
    vector<vector<int> > adj;
public:
    void dfs1(int cur = 0, int par = -1) {
        down[cur] = 0;
        num[cur] = 1;
        for(int nb : adj[cur]) {
            if(nb == par)
                continue;
            dfs1(nb, cur);
            down[cur] += down[nb] + num[nb];
            num[cur] += num[nb];
        }
    }

    void dfs2(int cur = 0, int par = -1) {
        if(par != -1) {
            int remSubtreeOfPar = ans[par] - (down[cur] + num[cur]);
            int upVal = remSubtreeOfPar + (num[0] - num[cur]);
            ans[cur] = down[cur] + upVal;
        }
        else
            ans[cur] = down[cur];

        for(int nb : adj[cur]) {
            if(nb == par)
                continue;
            dfs2(nb, cur);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        down.resize(n);
        num.resize(n);
        up.resize(n);
        ans.resize(n);
        adj.resize(n);

        for(vector<int> e : edges)
            adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);
        
        dfs1(); // finding the 'down' & 'num' values
        dfs2(); // finding the 'ans' values
        
        return ans;
    }
};