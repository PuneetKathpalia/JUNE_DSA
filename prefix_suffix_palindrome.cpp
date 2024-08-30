// Link : https://codeforces.com/contest/1326/problem/D2

#include<bits/stdc++.h>
using namespace std;

//largest prefix that matches a suffix
int kmp(string s)
{
	vector<int> lps(s.size(), 0);

	for (int i = 1; i < (int)lps.size(); ++i)
	{
		int prev_idx = lps[i - 1];

		while (prev_idx > 0 && s[i] != s[prev_idx])
		{
			prev_idx = lps[prev_idx - 1];
		}

		lps[i] = prev_idx + (s[i] == s[prev_idx] ? 1 : 0);
	}

	return lps[lps.size() - 1];
}

int largest_pre_pal(string s)
{
	string t = s + "?";

	reverse(s.begin(), s.end());

	t += s;

	return kmp(t);
}

int main()
{
    int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		int n = s.length();

		int l = 0;

		for (int i = 0, j = n - 1; i < j; i++, j--)
			if (s[i] == s[j])
				l++;
			else
				break;

		//remaining is s[l..n-l-1];
		string rem = s.substr(l, n - 2 * l);

		string ans = s.substr(0, l);

		if (rem.size())
		{
			int l_pre = largest_pre_pal(rem);

			reverse(rem.begin(), rem.end());
			int l_suf = largest_pre_pal(rem);

			if (l_pre > l_suf)
			{
				reverse(rem.begin(), rem.end());
				ans += rem.substr(0, l_pre);
			}

			else
				ans += rem.substr(0, l_suf);
		}

		ans += s.substr(n - l, l);

		cout << ans << '\n';
	}
	return 0;
}