#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    double mySqrt(int x, int p) {
        double beg = 0, end = x;
        double precision = pow(10, -p);
        while(end - beg >= precision) {
            double mid = (beg + end)/2.0;
            if(mid*mid <= x)
                beg = mid;
            else
                end = mid;
        }
        return beg;
    }
};
int main() {
    int n, p;
    cin >> n >> p;
    Solution sol;
    double ans = sol.mySqrt(n, p);
    // We go the answer which is correct till 2 decimal places
    // We need to get rid of remaining decimal places
    cout << fixed << setprecision(p) << ans;
}