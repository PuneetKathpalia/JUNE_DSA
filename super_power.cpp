#include <bits/stdc++.h>
using namespace std;

// Link : https://leetcode.com/problems/super-pow/

class Solution {
    const int mod = 1337;
    int powUnderMod(int a,int n) {
        if(!n)
            return 1;

        int pt = powUnderMod(a,n/2);
        
        // Multiply and take mod
        pt*=pt, pt%=mod;

        if(n%2)
            pt*=a,pt%=mod;

        return pt;
    }
public:
    int superPow(int a, vector<int>& b) {
        int ans = 1;
        a %= mod;
        for(int i = b.size() - 1; i >= 0; --i) {
            ans = (ans*powUnderMod(a, b[i]))%mod;
            a = powUnderMod(a, 10);
        }
        return ans;
    }
};

int main() {
	// your code goes here
	return 0;
}
