#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
    stack<int> s;
public:
    MyQueue() {
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        stack<int> temp;
        while(!s.empty())
            temp.push(s.top()), s.pop();
        
        int frontElement = temp.top();
        temp.pop();

        while(!temp.empty())
            s.push(temp.top()), temp.pop();

        return frontElement;
    }
    
    int peek() {
        stack<int> temp;
        while(!s.empty())
            temp.push(s.top()), s.pop();
        
        int frontElement = temp.top(); // don't pop this time;

        while(!temp.empty())
            s.push(temp.top()), temp.pop();

        return frontElement;
    }
    
    bool empty() {
        return s.empty();
    }
};


int main() {
	// your code goes here
	return 0;
}