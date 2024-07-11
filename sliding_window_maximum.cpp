// https://leetcode.com/problems/sliding-window-maximum/description/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        deque<int> q;
        vector<int> ans(n - k + 1);
        int ansId = 0;

        for (int i = 0; i < n; ++i) {
            // Push arr[i] to the deque strategically
            while (!q.empty() && arr[q.back()] <= arr[i])
                q.pop_back();
            q.push_back(i);

            // If the front element is out of the current window, then pop it out
            if (q.front() <= i - k) {
                q.pop_front();
            }

            // If we have processed at least k elements, add the maximum to the ans appropriately
            if (i >= k - 1) {
                ans[ansId] = arr[q.front()];
                ansId++;
            }
        }
        return ans;
    }
};