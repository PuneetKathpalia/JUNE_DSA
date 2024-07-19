#include<bits/stdc++.h>
using namespace std;

// Link : https://cses.fi/problemset/task/1081/

const int limit = 1000000;

int main()
{
    int n; cin >> n;
    vector<int> arr(n), freq(limit + 1);

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        freq[arr[i]] += 1;
    }

    int ans = -1;
    for(int gcd = limit; gcd >= 1; --gcd) {
        int cnt = 0;
        for(int num = gcd; num <= limit; num += gcd) {
            cnt += freq[num];
        }
        if(cnt >= 2) {
            ans = gcd;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}