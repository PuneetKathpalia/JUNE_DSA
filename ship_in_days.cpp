class Solution {
public:
    int reqDays(int cap, vector<int>& weights) {
        int curDay = 1, curLoad = 0;
        int n = weights.size();
        for(int i = 0; i < n; i++) {
            if(weights[i] <= cap - curLoad) {
                curLoad += weights[i];
            } else {
                curDay++;
                curLoad = 0;
                curLoad += weights[i];
            }
        }
        return curDay;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int min_cap = INT_MIN;
        int max_cap = 0;
        int n = weights.size();
        for(int i = 0; i < n; i++) {
            min_cap = max(min_cap, weights[i]);
            max_cap += weights[i];
        }
        int ans = -1;
        while(min_cap <= max_cap) {
            int mid_cap = min_cap + (max_cap - min_cap) / 2;
            int req_days = reqDays(mid_cap, weights);
            if(req_days <= days) {
                ans = mid_cap;
                max_cap = mid_cap - 1;
            } else {
                min_cap = mid_cap + 1;
            }
        } 
        // O(log(sum(ele)) * n)
        
        return ans;
        // for(int i = min_cap; i <= max_cap; i++) {
        //     int req_days = reqDays(i, weights);
        //     if(req_days <= days) return i;
        // }// O(sum(ele) * n)
        // // 5*10^4 * 500 * 5 * 10^4 = 125 * 10 ^10
        // return -1;
    }
};