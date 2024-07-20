#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

pair<int,int> extendedEuclid(int a, int b) {
	if(!b) {
		// cout << "a = " << a << " and b = " << b << '\n';
		// cout << "x = " << 1 << " and y = " << 0 << "\n\n";
		return {1, 0}; // 1*a + 0*b => a
	}

	pair<int,int> partialSol = extendedEuclid(b, a%b);
	int xPartial = partialSol.first, yPartial = partialSol.second;

	// cout << "a = " << a << " and b = " << b << '\n';
	// cout << "x = " << yPartial << " and y = " << xPartial - yPartial*(a/b) << "\n\n";

	return {yPartial, xPartial - yPartial*(a/b)};
}

int modInverse(int a, int m) {
	if(__gcd(a, m) != 1)
		return -1;
	int x = extendedEuclid(a, m).first;
	return (x%m + m)%m;
}

long long fact(int n) {
	long long ans = 1;
	for(int i = 1; i <= n; ++i)
		ans = (ans * i)%mod;
	return ans;
}

int countAnagramsWord(string s) {
	unordered_map<char, int> f;
	for(char ch : s)
		f[ch]++;

	long long ans = fact(s.length());

	for(auto p : f) {
		int curFreq = p.second;
		long long curFreqFact = fact(curFreq);
		ans = (ans * modInverse(curFreqFact, mod)) % mod;
	}

	return ans;
}

int main() {
	string s; cin >> s;
	cout << countAnagramsWord(s);
	return 0;
}