#include <bits/stdc++.h>
using namespace std;

// Link : https://www.codechef.com/problems/RD19

int main() {
	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n; cin >> n;
		int gc = 0;

		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			gc = __gcd(gc, x);
		}

		if (gc == 1)
			cout << 0 << '\n';
		else
			cout << -1 << '\n';
	}
	return 0;
}
