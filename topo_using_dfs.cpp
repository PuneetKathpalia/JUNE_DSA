// Link : https://leetcode.com/problems/course-schedule-ii/

class Solution {
	int n;
	vector<vector<int> > adj;

	bool DFS(int cur, vector<int> &vis, vector<int> &topo) {
		vis[cur] = 1; // recursion in progress

		for(int nb : adj[cur]) {
			if(!vis[nb]) {
				bool can = DFS(nb, vis, topo);
				if(!can)
					return false;
			}
			else if(vis[nb] == 1) {
				return false; // found a back-edge
			}
			// Nothing to be done for vis = 2.
		}

		vis[cur] = 2; // recursion done
		topo.push_back(cur); // add to the answer
		return true;
	}
    vector<int> TopoUsingDFS() {
		vector<int> ans, vis(n);

		for(int i = 0; i < n; ++i) {
			if(!vis[i]) {
				bool can = DFS(i, vis, ans);
				if(!can) {
					ans = {};
					break;
				}
			}
		}

		reverse(ans.begin(), ans.end());
		return ans;
	}

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
		adj.resize(n);

        for(vector<int> v : prerequisites)
			adj[v[1]].push_back(v[0]);

		vector<int> ans = TopoUsingDFS();
		return ans;
    }
};