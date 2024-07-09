#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
    list<int> ll;
public:
    MyQueue() {
    }
    
    void push_back(int x) {
        ll.push_back(x);
    }

    void push_front(int x) {
        ll.push_front(x);
    }
    
    int pop_front() {
        int frontElement = ll.front();
        ll.pop_front();
        return frontElement;
    }

    int pop_back() {
        int backElement = ll.back();
        ll.pop_back();
        return backElement;
    }
    
    int peek_front() {
        return ll.front();
    }

    int peek_back() {
        return ll.back();
    }
    
    bool empty() {
        return ll.empty();
    }
};

int main() {
	// your code goes here
	return 0;
}