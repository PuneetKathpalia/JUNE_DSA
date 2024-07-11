#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    queue<int> q;
    q.push(2);
    q.push(3);
    q.push(5);

    for(int i = 0; i < n - 1; ++i) {
        int x = q.front();
        q.pop();

        q.push(10*x + 2);
        q.push(10*x + 3);
        q.push(10*x + 5);
    }

    cout << q.front() << '\n';

	return 0;
}
