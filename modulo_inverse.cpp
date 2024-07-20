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

int main() {
	// int a, b; cin >> a >> b;
	// auto sol = extendedEuclid(a, b);

	// cout << sol.first << ' ' << sol.second << '\n';
	// cout << "GCD: " << __gcd(a, b);

	int a, m; cin >> a >> m;
	cout << modInverse(a, m);
	return 0;
}
