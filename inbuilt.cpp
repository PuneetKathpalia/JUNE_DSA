#include <bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<int, int> m;

	m.insert({1, 5});

	m[5] = 2; // m["pulkit"] = 100;

	if (m.count(10))
		cout << "10 present\n";
	else cout << "10 not present\n";

	cout << m[10] << '\n';

	if (m.count(10))
		cout << "10 present\n";

	auto it = m.find(10);

	if (it != m.end())
		it->second = 10;

	cout << m[10] << '\n';

	m.max_load_factor(0.25);
	m.reserve(1024);

	m.erase(10);

	if (m.count(10))
		cout << "10 present\n";
	else cout << "10 not present\n";

	cout << m.bucket_count() << '\n';
	return 0;
}