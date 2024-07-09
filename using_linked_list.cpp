#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
    list<int> ll;
public:
    MyQueue() {
    }
    
    void push(int x) {
        ll.push_back(x);
    }
    
    int pop() {
        int frontElement = ll.front();
        ll.pop_front();
        return frontElement;
    }
    
    int peek() {
        return ll.front();
    }
    
    bool empty() {
        return ll.empty();
    }
};

int main() {
	// your code goes here
	return 0;
}