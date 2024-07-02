#include<bits/stdc++.h>
using namespace std;

// Time : O(NlogN)
bool binarySearch(vector<int>& arr, int target) {
    int beg = 0, end = arr.size() - 1;
    while(beg <= end) {
        int mid = (beg + end)/2;
        if(arr[mid] == target)
            return true;
        else if(arr[mid] > target)
            end = mid - 1;
        else
            beg = mid + 1;
    }
    return false;
}
int binarySearchableCount(vector<int>& arr, int n) {
    int cnt = 0;
    for(int num : arr) {
        if(binarySearch(arr, num))
            cnt += 1;
    }
    return cnt;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    cout<<binarySearchableCount(arr,n);
}