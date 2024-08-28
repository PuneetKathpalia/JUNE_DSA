// Link : https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

class Solution {
public:
    int shortestPath(vector<vector<int> > &free, int k) {
	int n = free.size(), m = free[0].size();
    for(auto &v : free)
        for(auto &val: v)
            val = 1 - val;
	vector<vector<vector<int> > > dis(n, vector<vector<int> >(m, vector<int>(k+1, -1)));
    queue<vector<int> > q;
    q.push({0,0,0});
    dis[0][0][0] = 0;

    int di[] = {1, -1, 0, 0};
    int dj[] = {0, 0, -1, 1};

    while(!q.empty()) {
        vector<int> cur = q.front();

        if(cur[0] == n-1 and cur[1] == m-1) {
            return dis[cur[0]][cur[1]][cur[2]];
        }

        q.pop();
        for(int p = 0; p < 4; ++p) {
            int r = cur[0] + di[p], c = cur[1] + dj[p];
            if(r < 0 or r >= n or c < 0 or c >= m)
                continue;
            if(cur[2] == k and !(free[r][c]))
                continue;
            int blocked = !free[r][c];
            
            if(dis[r][c][cur[2] + blocked] == -1) {
                dis[r][c][cur[2] + blocked] = dis[cur[0]][cur[1]][cur[2]] + 1;
                q.push({r, c, cur[2] + blocked});
            }
        }
    }

    return -1;
}

};