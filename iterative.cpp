#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int iterativeBinarySearch(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int m = (l + r) / 2;

            if (nums[m] == target)
                return m;

            if (nums[m] > target) // go to [l, m - 1]
                r = m - 1;
            else // go to [m + 1, r]
                l = m + 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        return iterativeBinarySearch(nums, 0, nums.size() - 1, target);
    }
};

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    Solution sol;
    cout << sol.search(arr, target) << endl;

    return 0;
}
