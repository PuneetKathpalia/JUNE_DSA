class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>, greater<int>> q;
        int n = heights.size();
        for(int i = 1; i < n; i++) {
            int diff = heights[i] - heights[i-1];
            if(diff > 0) {
                q.push(diff);
            }
            if(q.size() > ladders) {
                int bricks_req = q.top();
                q.pop();
                if(bricks_req > bricks) {
                    return i-1;
                } else {
                    bricks -= bricks_req;
                }
            }
        }
        return n-1;
    }
};