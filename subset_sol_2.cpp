class Solution {
public:
    vector<vector<int>> ans;
    void subsetsHelper(vector<int>& nums, vector<int>& subset,int i) {
        if(i == nums.size()) {
            ans.push_back(subset);
            return;
        }

        // include ith element
…        subsetsHelper(nums, subset, 0);
        return ans;
    }
};