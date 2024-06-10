#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;

    for(int i = 0; i < 20; ++i) {
        cout << v.size() << ' ' << v.capacity() << '\n';
        v.push_back(i);
    }
  return 0;
}