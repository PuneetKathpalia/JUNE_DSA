class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> lis;
        lis.push_back(nums[0]);

        for(int i = 1; i < n; i ++) {
            if(nums[i] > lis.back()) {
                lis.push_back(nums[i]);
            } else {
                // for(int j = 0; j < lis.size(); j++) {
                //     if(lis[j] >= nums[i]) {
                //         lis[j] = nums[i];
                //         break;
                //     }
                // }
                int index = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                lis[index] = nums[i];
            }
        }
        return lis.size();
    }
};