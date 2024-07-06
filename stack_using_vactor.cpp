/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack *obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

/*
    Link : https://leetcode.com/problems/implement-stack-using-queues/
    Although they've asked to implement using queues, but we can still
    use the problem to check our solution.
*/

#include <bits/stdc++.h>
using namespace std;

class MyStack {
    private:
	vector<int> arr;

    public:
	MyStack() {
    }
    
    void push(int x) {
        arr.push_back(x);
    }
    
    int pop() {
        if(arr.size() == 0)
            return -1;
        int ans = arr.back();
        arr.pop_back();
        return ans;
    }
    
    int top() {
        if(arr.size() == 0)
            return -1;
        return arr.back();
    }
    
    bool empty() {
        return arr.size() == 0;
    }

    void clear() {
        while(!empty())
            pop();
    }
};

int main() {
	MyStack *s = new MyStack();
	s->push(5);
	s->push(4);
	s->push(3);
	cout<<s->top();
}
