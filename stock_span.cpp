#include <bits/stdc++.h>
using namespace std;

// Link : https://www.geeksforgeeks.org/problems/stock-span-problem/1

class Solution
{
    vector<int> prevGreaterElements(int nums[], int n) {
        stack<int> s;
        vector<int> ans(n);

        for(int i = 0; i < n; ++i) {
            while(s.size() && nums[s.top()] <= nums[i])
                s.pop();
            
            ans[i] = s.empty()? -1 : s.top();
            s.push(i);
        }

        return ans;
    }
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int> pge = prevGreaterElements(price, n);
       vector<int> ans(n);
       
       for(int i = 0; i < n; ++i)
            ans[i] = i - pge[i];
            
        return ans;
    }
};

int main() {
	// your code goes here
	return 0;
}