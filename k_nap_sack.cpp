#include<bits/stdc++.h>
using namespace std;

long long knapsackHelper(int i, vector<long long>& wt, vector<long long>& val, long long remCap, long long dp[100][100001]) {
  if(remCap < 0) return LLONG_MIN;
  if(remCap == 0) return 0;
  if(i >= wt.size()) return 0;
  if(dp[i][remCap] != -1) return dp[i][remCap];
  long long op1,op2;
  // pick it
  op1 = val[i] + knapsackHelper(i+1, wt, val, remCap - wt[i], dp);
  // skip it
  op2 = knapsackHelper(i+1, wt, val, remCap, dp);
  return dp[i][remCap] = max(op1,op2);
}
int main() {
  long long n, w;
  cin>>n>>w;
  
  vector<long long> wt(n);
  vector<long long> val(n);
  long long dp[100][100001];
  memset(dp,-1,sizeof dp);
  for(int i = 0; i < n; i++) {
    cin>>wt[i]>>val[i];
  }
  cout<<knapsackHelper(0,wt,val,w,dp);
}