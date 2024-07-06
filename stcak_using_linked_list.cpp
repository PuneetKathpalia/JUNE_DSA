/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */

/*
    Link : https://leetcode.com/problems/implement-stack-using-queues/
    Although they've asked to implement using queues, but we can still
    use the problem to check our solution.

    In this, we'll also see how to use in-built Linked List
    from java.util package.
*/

#include <bits/stdc++.h>
using namespace std;

class MyStack {
    forward_list<int> ll;
	public:

    MyStack() {
    }
    
    void push(int x) {
        ll.push_front(x);
    }
    
    int pop() {
		if(empty()) return -1;
        int ans = ll.front();
		ll.pop_front(); // Deletes the first and returns it.
        return ans;
    }
    
    int top() {
        return ll.front();
    }
    
    bool empty() {
		int size = distance(ll.begin(),
                        ll.end());
        return size == 0;
    }

    void clear() {
        ll.clear();
    }
};

int main() {
	MyStack *s = new MyStack();
	s->push(5);
	s->push(4);
	s->push(3);
	cout<<s->top();
}