#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int recursiveBinarySearch(vector<int>& nums, int l, int r, int target) {
        if (l > r)
            return -1;

        int m = (l + r) / 2;

        if (nums[m] == target)
            return m;

        if (nums[m] < target)
            return recursiveBinarySearch(nums, m + 1, r, target);

        return recursiveBinarySearch(nums, l, m - 1, target);
    }

    int search(vector<int>& nums, int target) {
        return recursiveBinarySearch(nums, 0, nums.size() - 1, target);
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
