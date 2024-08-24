// Link : https://leetcode.com/problems/course-schedule-ii/ 

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> indeg(n), vis(n);
        vector<vector<int>> adj(n);
        
        for(vector<int> e : prerequisites) {
            adj[e[1]].push_back(e[0]);
            indeg[e[0]] += 1;
        }
        
        queue<int> q;
        for(int i = 0; i < n; ++i)
            if(indeg[i] == 0) {
                q.push(i);
                vis[i] = 1;
            }
        
        vector<int> ans;
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            ans.push_back(cur);

            for(int nb : adj[cur]) {
                if(vis[nb])
                    continue;
                indeg[nb] -= 1;
                if(indeg[nb])
                    continue;
                vis[nb] = true;
                q.push(nb);
            }
        }

        if(ans.size() < n)
            ans.clear();
        
        return ans;
    }
};