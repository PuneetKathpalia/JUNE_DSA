class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=-1,mini=INT_MAX;
        for(int j=0;j<nums.size();j++){
            if(nums[j]>mini){
                ans=max(ans,nums[j]-mini);
            }
            mini=min(mini,nums[j]);
        }
        return ans;
    }
};