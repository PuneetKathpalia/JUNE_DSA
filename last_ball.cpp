#include <bits/stdc++.h>
using namespace std;

double dp[2001][2001]; // [number of white balls][number of black balls]
bool done[2001][2001];

int C2(int n) {
    if(n < 2)
        return 0;
    
    return n*(n-1)/2;
}

double prob(int w, int b) {
    if(w < 0 || b < 0)
        return 0.0;
    if(w == 0 && b == 1)
        return 0.0;
    if(w == 1 && b == 0)
        return 1.0;

    if(done[w][b])
        return dp[w][b];

    // Both white
    double pw = C2(w)/(double)C2(w+b);
    
    // Both black
    double pb = C2(b)/(double)C2(w+b);

    // 1 white & 1 black
    double pbw = 1.0 - pw - pb;

    dp[w][b] = (pb + pbw) * prob(w, b - 1) + pw * prob(w - 2, b + 1);
    done[w][b] = true;
    return dp[w][b];
}

int main() {
    for(int w = 1; w <= 10; ++w) {
        for(int b = 1; b <= 10; ++b) {
            cout << w << ' ' << b << ": " << prob(w, b) << '\n';
        }
    }
}