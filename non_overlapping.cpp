#include <bits/stdc++.h>
using namespace std;

#define int long long

// 1 <= n <= 1e4

int32_t main() {
    int n; cin >> n;
    int nC2 = n*(n-1)/2;
    int nC3 = n*(n-1)*(n-2)/6;
    int nC4 = n*(n-1)*(n-2)*(n-3)/24;
    cout << nC2 + 2*nC3 + nC4 << '\n';
	return 0;
}
