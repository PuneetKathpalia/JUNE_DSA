#include <bits/stdc++.h>
using namespace std;

bool isValid(string str) {
	stack<int> s;
	for(int i = 0; i < str.size(); ++i) {
		char ch = str[i];
		if(ch == '[')
			s.push(']');
		else if(ch == '{')
			s.push('}');
		else if(ch == '(')
			s.push(')');
		else if(s.empty() || s.top() != ch)
			return false;
		else
			s.pop();
	}
	return s.empty();
}

int main() {
	string s;
	cin>>s;
	cout<<isValid(s);
	return 0;
}