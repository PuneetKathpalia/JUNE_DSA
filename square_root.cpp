#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int mySqrt(int x) {
        int beg = 0, end = x, ans = -1;
        while(beg <= end) {
            // 'long' because otherwise
            // mid*mid can overflow
            long mid = (beg + end)/2;

            if(mid*mid <= x) {
                ans = (int)mid;
                beg = (int)mid + 1;
            }
            else
                end = (int)mid - 1;
        }
        return ans;
    }
};

int main() {
    int n;
    cin>>n;
    Solution sol;
    cout<<sol.mySqrt(n);
}