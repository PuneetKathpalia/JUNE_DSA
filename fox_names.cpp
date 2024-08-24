// Link : https://codeforces.com/contest/510/problem/C

#include<bits/stdc++.h>
using namespace std;

vector<int> adj[26];
int indeg[26];

string getTopo() {
    string ans;
	queue<int> q;

	for (int i = 0; i < 26; ++i)
		if (!indeg[i])
			q.push(i);

	while (!q.empty())
	{
		int i = q.front();
        ans += (char)('a' + i);
		q.pop();

		for (int j : adj[i]) {
			indeg[j]--;
			if (!indeg[j])
				q.push(j);
		}
	}

	if (ans.size() < 26)
		return "Impossible";
    
    return ans;
}

int main() {
	int n; cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	for (int i = 0; i + 1 < n; ++i) {
		int id = 0;
		while (id < min(v[i].size(), v[i + 1].size()) and v[i][id] == v[i + 1][id])
			id++;

		if (id < min(v[i].size(), v[i + 1].size()))
			adj[v[i][id] - 'a'].push_back(v[i + 1][id] - 'a'), indeg[v[i + 1][id] - 'a']++;

		else if (id >= v[i + 1].size()) {
			cout << "Impossible\n";
			return 0;
		}
	}

	cout << getTopo() << '\n';

	return 0;
}