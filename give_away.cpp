#include <bits/stdc++.h>
using namespace std;

// Link : https://www.codechef.com/KA19MOS/problems/GVAWAY

int main() {
    int t; cin >> t;
    while(t--) {
        int l, r, k; cin >> l >> r >> k;

        if(l == r)
            cout << 1 << '\n';
        else
            cout << k << '\n';
    }
	return 0;
}
