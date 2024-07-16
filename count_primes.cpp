#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<bool> primeSieve(int n) {
        vector<bool> isPrime(n+1, true);
        isPrime[0] = isPrime[1] = false;

        for(int i = 2; i <= n; ++i) {
            if(!isPrime[i] or (long long)i*i > n)
                continue;
            for(int j = i*i; j <= n; j += i) // multiples of i
                isPrime[j] = false;
        }

        return isPrime;
    }
public:
    int countPrimes(int n) {
        vector<bool> p = primeSieve(n);
        int ans = 0;
        for(int i = 2; i < n; ++i)
            if(p[i])
                ans++;
        return ans;
    }
};

int main() {
	// your code goes here
	return 0;
}