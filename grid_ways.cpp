#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

int f[200001];

int pwmd(int a, int n = mod-2) { // modulo inverse
    if(!n)
        return 1;
    int pt = pwmd(a,n/2);
    pt*=pt,pt%=mod;
    if(n&1)
        pt*=a,pt%=mod;
    return pt;
}

int nCr(int n, int r) {
    if(r > n)
        return 0;
    int num = f[n];
    int den = (f[r] * f[n-r]) % mod;
    return (num * pwmd(den)) % mod;
}

void pre() {
    f[0] = 1;
    for(int i = 1; i <= 200000; ++i)
        f[i] = (f[i-1] * i) % mod;
}

int32_t main() {
    int q; cin >> q;
    pre();
    while(q--) {
        int n, m; cin >> n >> m;
        cout << nCr(n + m - 2, n - 1);
    }
	return 0;
}
