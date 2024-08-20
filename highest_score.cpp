// Link : https://leetcode.com/problems/count-nodes-with-the-highest-score/

class Solution {
    vector<vector<int> > adj;
    vector<int> sub;
    int n;
    long long maxScore;
    int maxScoreCnt;
    void dfs(int cur = 0, int par = -1) {
        long long curScore = 1;
        sub[cur] = 1;
        for(int nb : adj[cur]) {
            if(nb == par)
                continue;
            dfs(nb, cur);
            sub[cur] += sub[nb];
            curScore *= sub[nb];
        }
        if(cur)
            curScore *= (n - sub[cur]);
        cout << cur << ' ' << curScore << '\n';
        
        if(curScore > maxScore)
            maxScoreCnt = 1, maxScore = curScore;
        else if(curScore == maxScore)
            maxScoreCnt += 1;
    }
public:
    int countHighestScoreNodes(vector<int>& p) {
        n = p.size();
        maxScore = 0;
        maxScoreCnt = 0;
        adj.resize(n);
        sub.assign(n, 0);
        for(int i = 0; i < n; ++i)
            if(p[i] != -1) {
                adj[i].push_back(p[i]);
                adj[p[i]].push_back(i);
            }
        dfs();
        return maxScoreCnt;
    }
};