#include <bits/stdc++.h>
using namespace std;

// Link : https://codeforces.com/contest/312/problem/B

int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    double Wa = a/(double)b, Wb = c/(double)d;
    double La = 1.0 - Wa, Lb = 1.0 - Wb;

    double ans = Wa / (1 - La*Lb);

    cout << ans << '\n';
	return 0;
}