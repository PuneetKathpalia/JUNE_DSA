#include<bits/stdc++.h>
using namespace std;

// Time : O(N)
int randomBinarySearchable(int arr[], int n) {
        int preMax[n];
        int sufMin[n];

        for(int i = 0; i < n; ++i)
            preMax[i] = i == 0? arr[i] : max(arr[i], preMax[i-1]);

        for(int i = n - 1; i >= 0; --i)
            sufMin[i] = i == n - 1? arr[i] : min(arr[i], sufMin[i+1]);

        int cnt = 0;

        for(int i = 0; i < n; ++i) {
            int leftMax = (i == 0)? INT_MIN : preMax[i - 1];
            int rightMin = (i == n-1)? INT_MAX : sufMin[i + 1];

            if(arr[i] > leftMax && arr[i] < rightMin)
                cnt++;
        }
        return cnt;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    cout<<randomBinarySearchable(arr,n);
}