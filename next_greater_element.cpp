#include <bits/stdc++.h>
using namespace std;

// Link : https://www.geeksforgeeks.org/problems/next-larger-element/1

// Time : O(N)
// Space : O(N)

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long>& arr, int n) {
        stack<long long> s;
        vector<long long> ans(n);

        for(int i = n - 1; i >= 0; --i) {
            while(s.size() && s.top() <= arr[i])
                s.pop();
            
            ans[i] = s.empty()? -1 : s.top();
            s.push(arr[i]);
        }

        return ans;
    }
};

int main() {
	// your code goes here
	return 0;
}