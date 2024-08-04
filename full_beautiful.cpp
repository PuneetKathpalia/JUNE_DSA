#include <bits/stdc++.h>
using namespace std;

// Link : https://www.codechef.com/problems/BEAUTPAR

#define int long long

vector<int> getCuts(vector<int> val, vector<int> index) {
    if(val.empty()) {
        return vector<int>{};
    }

    vector<int> dp(val.size() + 1, LLONG_MAX), idVal(val.size() + 1, -1), par(val.size() + 1, -1);
    dp[0] = LLONG_MIN;
    for(int i = 0; i < val.size(); ++i) { // keep updating dp
        int id = lower_bound(dp.begin(), dp.end(), val[i]) - dp.begin();
        if(id < dp.size()) {
            dp[id] = val[i];
            idVal[id] = i;
            par[idVal[id]] = idVal[id-1];
        }
    }

    int len = 1;
    while(len < val.size() && dp[len+1] < LLONG_MAX)
        len += 1;

    vector<int> ans;
    int id = idVal[len];
    while(id >= 0)
        ans.push_back(index[id]), id = par[id];
    reverse(ans.begin(), ans.end());
    return ans;
}

int32_t main() {
	// your code goes here
	int t; cin >> t;
	while(t--) {
	    int n, k; cin >> n >> k;
	    vector<int> a(n), pre(n);
	    
	    for(int i = 0; i < n; ++i) {
	        cin >> a[i];
	        pre[i] = i == 0? a[i] : pre[i-1] + a[i];
	    }
	    
	    if(k == 1) {
            if(pre[n-1] > 0)
                cout << "YES\n" << n << '\n';
            else
                cout << "NO\n";
	        continue;
	    }
	    
	    // Add the valid pre values and their corresponding
	    // indices to 2 new different vectors
	    vector<int> val, index;
	    for(int i = 0; i < n - 1; ++i) {
	        if(pre[i] > 0 && pre[i] < pre[n - 1]) {
	            val.push_back(pre[i]);
	            index.push_back(i);
	        }
	    }
	    
	    // Find the LIS out of this val array.
	    vector<int> cuts = getCuts(val, index);
	    
	    if(cuts.size() < k - 1)
	        cout << "NO\n";
	   else {
	       cout << "YES\n";
	       
	       // length of 1st part
	       cout << cuts[0] + 1 << ' ';
	       
	       // lengths of all the parts in b/w
	       for(int i = 1; i < k - 1; ++i)
	        cout << cuts[i] - cuts[i-1] << ' ';
	       
	       // length of last part
	       cout << n - 1 - cuts[k-2] << '\n';
	   }
	}
}
