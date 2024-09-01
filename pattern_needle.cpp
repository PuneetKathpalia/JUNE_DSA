// Link : https://www.spoj.com/problems/NAJPF/

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int p = 31, m1 = 1000000007, m2 = 998244353;

int getHash(const string &s, int mod) {
    int ans = 0;
    for(char ch : s) {
        int d = ch - 'a' + 1;
        ans = (ans * p + d) % mod;
    }
    return ans;
}

int powMod(int exp, int mod) {
    if(exp == 0)
        return 1;
    int part = powMod(exp/2, mod);
    part = (part * part) % mod;

    return exp & 1 ? (part * p) % mod : part;
}

vector<int> rabinKarp(const string &str, const string &pat) {
    int hp1 = getHash(pat, m1), hp2 = getHash(pat, m2), lp = pat.length();
    int hs1 = getHash(str.substr(0, lp), m1), hs2 = getHash(str.substr(0, lp), m2); // getHash(str[0....lp-1])

    vector<int> ans;
    if(hs1 == hp1 && hs2 == hp2)
        ans.push_back(1);
    
    int powP1 = powMod(lp-1, m1), powP2 = powMod(lp-1, m2);
    for(int s = 1, e = lp; e < str.length(); ++s, ++e) {
        // Get rid of str[s - 1];
        int digDel = str[s - 1] - 'a' + 1;
        hs1 = (hs1 - digDel*powP1) % m1, hs2 = (hs2 - digDel*powP2) % m2;
        hs1 = (hs1 + m1) % m1, hs2 = (hs2 + m2) % m2;

        // Left shift & add str[e];
        int digAdd = str[e] - 'a' + 1;
        hs1 = (hs1 * p + digAdd) % m1;
        hs2 = (hs2 * p + digAdd) % m2;

        if(hs1 == hp1 && hs2 == hp2)
            ans.push_back(s + 1);
    }
    return ans;
}

int32_t main() {
	FIO;
    int t; cin >> t;
    while(t--) {
        string a, b; cin >> a >> b;
        vector<int> ids = rabinKarp(a, b);
        if(ids.empty()) {
            cout << "Not Found\n";
        }
        else {
            cout << ids.size() << '\n';
            for(int id : ids)
                cout << id << ' ';
            cout << '\n';
        }
    }
	return 0;
}
