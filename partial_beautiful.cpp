#include <bits/stdc++.h>
using namespace std;

// Link : https://www.codechef.com/problems/BEAUTPAR

#define int long long

int getLISlen(vector<int> val) {
    if(val.empty()) {
        return 0;
    }

    vector<int> dp(val.size() + 1, LLONG_MAX);
    dp[0] = LLONG_MIN;
    for(int i = 0; i < val.size(); ++i) { // keep updating dp
        int id = lower_bound(dp.begin(), dp.end(), val[i]) - dp.begin();
        if(id < dp.size())
            dp[id] = val[i];
    }

    int len = 1;
    while(len < val.size() && dp[len+1] < LLONG_MAX)
        len += 1;

    return len;
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
                cout << "YES\n";
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
	    int cuts = getLISlen(val);
	    
	    if(cuts < k - 1)
	        cout << "NO\n";
	   else
	       cout << "YES\n";
	}
}
