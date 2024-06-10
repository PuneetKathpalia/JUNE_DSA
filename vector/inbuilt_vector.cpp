#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<int> v1;
    vector<int> v2(5, 10);
    vector<int> v3 = {5, 1, 3, 2};

    cout << v2.size() << '\n';

    for(int i = 0; i < v2.size(); ++i)
        cout << v2[i] << ' ';
    cout << '\n';

    for(int i = 0; i < v3.size(); ++i)
        cout << v3[i] << ' ';
    cout << '\n';


    v1.push_back(5);
    v3.push_back(10);
    v3.push_back(15);

    for(int i = 0; i < v3.size(); ++i)
        cout << v3[i] << ' ';
    cout << '\n';

    for(int i = 0; i < v1.size(); ++i)
        cout << v1[i] << ' ';
    cout << '\n';

    v3.pop_back();
    v3[0] = 100;
    
    for(int i = 0; i < v3.size(); ++i)
        cout << v3[i] << ' ';
    cout << '\n';

    cout << v3.capacity();

        
  return 0;
}