#include <bits/stdc++.h>
using namespace std;

// Link : https://leetcode.com/problems/find-greatest-common-divisor-of-array/


class Solution {
    int gcd(int a, int b) {
        if(b == 0)
            return a;
        return gcd(b, a%b);
    }
public:
    int findGCD(vector<int>& nums) {
        int largest = *max_element(nums.begin(), nums.end());
        int smallest = *min_element(nums.begin(), nums.end());
        return gcd(largest, smallest);
    }
};

int main() {
	// your code goes here
	return 0;
}
