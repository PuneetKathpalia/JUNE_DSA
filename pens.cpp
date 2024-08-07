#include <bits/stdc++.h>
using namespace std;

int pen[(1<<20)];

int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;

        memset(pen, 0, sizeof(pen));
        for(int i = 0; i < k; ++i) {
            string pi; cin >> pi;
            int mi = 0;
            for(char ch : pi) {
                int bit = ch - 'a';
                mi += (1<<bit);
            }
            pen[mi] = i + 1;
        }

        for(int m = (1<<20) - 1; m >= 0; --m) {
            for(int i = 0; i < 20; ++i) {
                if(!((m>>i)&1) && pen[m|(1<<i)])
                    pen[m] = pen[m|(1<<i)];
                if(pen[m])
                    break;
            }
        }

        // Now, let's move to the string;
        int i = 0, ans = 0;
        while(i < n) {
            int j = i + 1, subset = (1<<(s[i]-'a'));
            while(j < n) {
                int bit = s[j] - 'a';
                if(!pen[subset | (1<<bit)])
                    break;
                subset |= (1<<bit);
                j++;
            }
            
            for(int id = i; id < j; ++id)
                cout << pen[subset] << ' ';

            i = j;
        }
        cout << '\n';
    }
	return 0;
}
