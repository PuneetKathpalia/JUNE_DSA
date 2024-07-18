#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int LIMIT = 5000000;

vector<int> primeSieve(int n = LIMIT) {
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

int getPrimeCnt(int num, vector<int> &spf) {
    int ans = 0;
    while(num > 1) {
        int pf = spf[num], cnt = 0;
        while(num%pf == 0) {
            num /= pf;
            cnt += 1;
        }
        ans += cnt;
    }
    return ans;
}

int main() {
    FIO;
    vector<int> spf = primeSieve();
    vector<int> pref(LIMIT+1);
    for(int i = 2; i <= LIMIT; ++i) {
        int ansOfI = getPrimeCnt(i, spf);
        pref[i] = pref[i-1] + ansOfI;
    }

    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        cout << pref[a] - pref[b] << '\n';
    }
	return 0;
}