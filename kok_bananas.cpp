// class Solution {
// public:
//     long reqHours(long speed, vector<int>& piles) {
//         long hours = 0;
//         int n = piles.size();
//         for(int i = 0; i < n; i++) {
//             hours += (piles[i] / speed);
//             if(piles[i] % speed) hours++;
//         }
//         return hours;
//     } // O(N)
//     int minEatingSpeed(vector<int>& piles, int h) {
//         long min_speed = 1;
//         long max_speed = piles[0];
//         int n = piles.size();
//         for(int i = 0; i < n; i++) {
//             max_speed = max(max_speed, (long)piles[i]);
//         } // O(N)
//         int ans = -1;
//         while(min_speed <= max_speed) {
//             long mid_speed = min_speed + (max_speed - min_speed) / 2;
//             long req_hours = reqHours(mid_speed, piles); // O(N)
//             if(req_hours <= h) {
//                 ans = mid_speed;
//                 max_speed = mid_speed - 1;
//             } else {
//                 min_speed = mid_speed + 1;
//             }
//         } // O(log(max_ele) * n)
//         return ans;
//         // for(int i = min_speed; i <= max_speed; i++) {
//         //     if(reqHours(i,piles) <= h) return i;
//         // } // O(max(ele) * n)
//     }
// };