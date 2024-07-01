#include <bits/stdc++.h>
using namespace std;

long long reqBalloons(long long max_candies, vector<long long>& balloon_demand, vector<long long>& candies_per_balloon) {
    long long req_balloons = 0;
    int n = balloon_demand.size();
    
    for(int i = 0; i < n; i++) {
        if(candies_per_balloon[i] == 0) continue;
        req_balloons += max((long long)0,(balloon_demand[i] - (max_candies / candies_per_balloon[i])));
    }
    return req_balloons;
}
int main() {
	long long n, m;
	cin >> n >> m;
	vector<long long> balloon_demand(n);
	vector<long long> candies_per_balloon(n);
	
	for(int i = 0; i < n; i++) {
	    cin >> balloon_demand[i];
	}
	for(int i = 0; i < n; i++) {
	    cin >> candies_per_balloon[i];
	}
	
	long long min_thershold = 0, max_thershold = LONG_LONG_MIN;
	
	for(int i = 0; i < n; i++) {
	    max_thershold = max(max_thershold, balloon_demand[i] * candies_per_balloon[i]);
	}
	long long ans;
	while(min_thershold <= max_thershold) {
	    long long mid_thershold = min_thershold + (max_thershold - min_thershold) / 2;
	    long long req_balloons = reqBalloons(mid_thershold, balloon_demand, candies_per_balloon);
	    if(req_balloons <= m) {
	        ans = mid_thershold;
	        max_thershold = mid_thershold - 1;
	    } else {
	        min_thershold = mid_thershold + 1;
	    }
	} 
	//O(log(max(ai*bi) * n)
// 	for(long long i = min_thershold; i <= max_thershold; i++) {
// 	    long long req_balloons = reqBalloons(i, balloon_demand, candies_per_balloon);
// 	    if(req_balloons <= m) {
// 	        cout<<i;
// 	        break;
// 	    }
// 	}
    cout<<ans;
	return 0;
}
