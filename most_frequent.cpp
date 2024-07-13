#include <bits/stdc++.h>
using namespace std;

// Link : https://leetcode.com/problems/most-frequent-even-element/d

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> f;
        
        for(int num : nums)
            f[num]++;

        int maxFreq = 0, ansElement = -1;
        for(pair<int,int> p : f) {

			// p.first -> array element / key
			// p.second -> frequency / value
			
            if((p.first%2) > 0 or p.second < maxFreq)
                continue;

            if(p.second > maxFreq or p.first < ansElement) {
                maxFreq = p.second;
                ansElement = p.first;
            }
        }
        return ansElement;
    }
};

int main() {
	// your code goes here
	return 0;
}