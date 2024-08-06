#include <bits/stdc++.h>
using namespace std;

// Link : https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int num : nums) 
            ans ^= num;
        return ans;
    }
};

int main() {
	// your code goes here
	return 0;
}
