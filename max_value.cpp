#include <bits/stdc++.h>
using namespace std;

// Link : https://leetcode.com/problems/max-value-of-equation/

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<int> q;
        int finalAns = INT_MIN;
        // Iterate on all j values.
        for(int j = 0; j < points.size(); ++j) {

            // Pop the ones that are invalid
            // now & have gone out of the window
            while(q.size() && points[q.front()][0] < points[j][0] - k)
                q.pop_front();

            // If there is a valid i left
            if(q.size()) {
                int i = q.front();
                int curAns = points[i][1] + points[j][1] + points[j][0] - points[i][0];
                finalAns = max(finalAns, curAns);
            }

            // Adding afterwards because
            // i < j, and not i <= j
            int y_minus_x = points[j][1] - points[j][0];
            while(q.size() && points[q.back()][1] - points[q.back()][0] <= y_minus_x)
                q.pop_back();
            // then push the current index.
            q.push_back(j);
        }
        return finalAns;
    }
};

int main() {
	// your code goes here
	return 0;
}
