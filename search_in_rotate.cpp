// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int l = 0, r = nums.size() - 1;
//         int lastEle = nums[r];
//         while(l <= r) {
//             int mid = (l + r) / 2;
//             if(target > lastEle && nums[mid] <= lastEle) {
//                 // target is in 1st region and we are in 2nd region
//                 // so we should go to the left side
//                 r = mid - 1;
//             } else if(target <= lastEle && nums[mid] > lastEle) {
//                 // target is in 2nd region and we are in 1st region
//                 // so we should go to the right side
//                 l = mid + 1;
//             } else {
//                 if(nums[mid] == target) {
//                     return mid;
//                 }else if(nums[mid] < target) {
//                     l = mid + 1;
//                 }else {
//                     r = mid - 1;
//                 }
//             }
//         }
//         return -1;
//     }
// };