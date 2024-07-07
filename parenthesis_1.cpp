#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
	int open = 0;
	for(int i = 0; i < s.size(); ++i)
		if(s[i] == '(') {
			open += 1;
		}
		else if(open == 0){
			return false;
		}
		else {
			open -= 1;
		}
	return open == 0;
}

int main() {
	string s;
	cin>>s;
	cout<<isValid(s);
	return 0;
}