#include <bits/stdc++.h>
using namespace std;

// Link : https://www.geeksforgeeks.org/problems/finding-the-numbers/1

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0;
        for(int num : nums)
            res ^= num;

        // Let's find rightmost set bit
        int thatBit = res - (res&(res-1));
        int a = 0, b = 0;

        for(int num : nums) {
            if(num & thatBit)
                a ^= num;
            else
                b ^= num;
        }
        
        if(a > b)
            swap(a, b);

        return vector<int>{a, b};
    }
};


int main() {
	// your code goes here
	return 0;
}
