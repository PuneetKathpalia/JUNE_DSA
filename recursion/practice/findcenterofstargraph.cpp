class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // The center of the star graph will appear in the first two edges.
        int u1 = edges[0][0], v1 = edges[0][1];
        int u2 = edges[1][0], v2 = edges[1][1];
        
        // The center node must be one of the nodes in the first edge and
        // must also appear in the second edge.
        if (u1 == u2 || u1 == v2) {
            return u1;
        } else {
            return v1;
        }
    }
};