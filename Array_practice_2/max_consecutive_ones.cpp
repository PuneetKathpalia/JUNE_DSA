class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zerocount=0,ans=0;;
        int l=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]==0){
                zerocount++;
            }
            while(zerocount>k){
                if(nums[l]==0){
                    zerocount--;
                }
                l++;
            }
            if(r-l+1>ans){
                ans=r-l+1;
            }
        }
        return ans;
    }
};