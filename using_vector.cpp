#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
    vector<int> v;
    int front;
public:
    MyQueue() {
        front = 0;
    }
    
    void push(int x) {
        v.push_back(x);
    }
    
    int pop() {
        int frontElement = v[front];
        front += 1;
        return frontElement;
    }
    
    int peek() {
        return v[front];
    }

    int size() {
        return v.size() - front;
    }
    
    bool empty() {
        return size() == 0;
    }
};

int main() {
	// your code goes here
	return 0;
}