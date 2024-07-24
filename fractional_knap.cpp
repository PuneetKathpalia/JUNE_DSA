#include <bits/stdc++.h>
using namespace std;

// Link : https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
// Time : O(NlogN)

struct Item{
    int value;
    int weight;
};

bool cmp(Item i1, Item i2) {
    return i1.value*i2.weight > i2.value*i1.weight;
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, cmp);
        double ans = 0.0;
        for(int i = 0; i < n; ++i) {
            if(W >= arr[i].weight) {
                W -= arr[i].weight;
                ans += arr[i].value;
            }
            else {
                ans += (W/(double)arr[i].weight)*arr[i].value;
                break;
            }
        }
        return ans;
    }
        
};

//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}