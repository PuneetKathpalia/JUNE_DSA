#include <bits/stdc++.h>
using namespace std;

// Link : https://codeforces.com/problemset/problem/1881/D

int main() {
	int t;
	cin >> t;

	while(t--) {
		int n;
		cin >> n;
		unordered_map<int,int> primeFreq;
		for(int i = 0; i < n; i++) {
			int ai;
			cin >> ai;
			for(int num = 2; num*num <= ai; num++) {
				while(ai % num == 0) {
					primeFreq[num]++;
					ai /= num;
				}
			}
			if(ai > 1) primeFreq[ai]++;
		}
		int flag = 1;
		for(auto a : primeFreq) {
			if(a.second % n != 0) {
				cout<<"NO"<<endl;
				flag = 0;
				break;
			} 
		}
		if(flag == 1) {
			cout<<"YES"<<endl;
		}

	}
	return 0;
}