// class Solution {
// public:
//     int findUnsortedSubarray(vector<int>& nums) {
//         vector<int> sorted_nums=nums;
//         sort(sorted_nums.begin(),sorted_nums.end());
//         int s=-1,e=-2;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]!=sorted_nums[i]){
//             if(s==-1) s=i;
//             else e=i;
//         }
//         }
//         return e-s+1;
//     }

// };