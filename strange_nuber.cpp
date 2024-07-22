#include <bits/stdc++.h>
using namespace std;

// Link : https://www.codechef.com/problems/STRNO

int main() {
	int t;
	cin >> t;
	while(t--) {
		int x, k;
		cin >> x >> k;
		int primeFactorCount = 0;
		for(int num = 2; num*num <= x; num++) {
			while(x % num == 0) {
				primeFactorCount++;
				x /= num;
			}
		}
		if(x > 1) primeFactorCount++;

		if(primeFactorCount >= k) {
			cout<<1<<endl;
		} else {
			cout<<0<<endl;
		}
	}
	return 0;
}