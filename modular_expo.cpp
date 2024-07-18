#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9 + 7;

ll mul(ll a, ll b) {
    return ((a%mod) * (b%mod))%mod;
}

ll sub(ll a, ll b) {
    return ((a%mod) - (b%mod) + mod)%mod;
}

ll add(ll a, ll b) {
    return ((a%mod) + (b%mod))%mod;
}

ll powUnderMod(ll a,ll n)
{
    if(!n)
        return 1;

    ll pt = powUnderMod(a,n/2);
    
    // Multiply and take mod
    pt = mul(pt, pt);

    if(n%2)
        return mul(pt, a);

    return pt;
}

int main() {
	// your code goes here
	return 0;
}
