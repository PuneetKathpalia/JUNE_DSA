#include <bits/stdc++.h>
using namespace std;

vector<int> primeSieve(int n) {
    vector<int> spf(n+1); // each value is 0 initially

    for(int i = 2; i <= n; ++i) {
        if(spf[i])
            continue;

        spf[i] = i;
        if((long long)i*i > n)
            continue;

        for(int j = i*i; j <= n; j += i) // multiples of i
            if(!spf[j])
                spf[j] = i;
    }

    return spf;
}

int main() {
    int n; cin >> n;
    vector<int> spf = primeSieve(1000000);
    while(n--) {
        int x; cin >> x;
        int ans = 1;
        while(x > 1) { // LogX
            int prime = spf[x], pcnt = 0;
            while(x % prime == 0)
                x /= prime, pcnt++;
            ans *= (1 + pcnt);
        }
        cout << ans << '\n';
    }
	return 0;
}
