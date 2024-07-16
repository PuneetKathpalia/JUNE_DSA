#include <bits/stdc++.h>
using namespace std;

map<int,int> primeFactors(int n) {
    map<int,int> ans;
    for(int i = 2; i*i <= n; ++i) {
        if(n%i)
            continue;
        int power = 0;
        while(!(n%i))
            n /= i, power += 1;
        ans[i] = power;
    }
    if(n > 1)
        ans[n] = 1;
    return ans;
}

int main() {
	int n; cin >> n;
    auto ans = primeFactors(n);

    for(auto p : ans)
        cout << p.first << ": " << p.second << '\n';
	return 0;
}
