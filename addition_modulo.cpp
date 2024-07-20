#include <bits/stdc++.h>
using namespace std;

long addUnderModulo(long a, long b, long m) {
	if(b == 0) return 0;
	long halfAns = addUnderModulo(a, b / 2, m);
	if(b % 2 == 0) {
		return (halfAns + halfAns) % m;
	} else {
		return ((halfAns + halfAns) % m + a) % m;
	}
}

int main() {
	long long a, b, m;
	cin >> a >> b >> m;
	cout<<addUnderModulo(a, b, m);
	return 0;
}
