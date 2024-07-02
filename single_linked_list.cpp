#include <bits/stdc++.h>
using namespace std;

// Link : https://leetcode.com/problems/design-linked-list/description/

class Node {
    public:
        int data;
        Node *next;

        Node(int val) {
            data = val;
            next = NULL;
        }
};

class MyLinkedList {
    Node *head;
    int length;
public:
    MyLinkedList() {
        head = NULL;
        length = 0;
    }
    
    int get(int index) {
        if(index < 0 or index >= this->length)
            return -1;

        Node *cur = this->head;

        for(int i = 0; i < index; i++) {
            cur = cur->next;
        }

        return cur->data;
    }
    
    void addAtHead(int val) {
        Node *newHead = new Node(val);
        newHead->next = this->head;
        this->head = newHead;
        this->length += 1;
    }
    
    void addAtTail(int val) {
        // If empty, then use the other function
        if(this->head == NULL) {
            addAtHead(val);
            return;
        }

        // Go to tail first
        Node *cur = this->head;
        while(cur->next != NULL)
            cur = cur->next;

        // Now, add a new tail to the cur tail's next
        Node *newTail = new Node(val);
        cur->next = newTail;

        this->length += 1;        
    }
    
    void addAtIndex(int index, int val) {
        if(index == 0) {
            addAtHead(val);
            return;
        }

        if(index > this->length)
            return;

        // Need to stop 1 before the end.
        Node *cur = this->head;
        for(int i = 0; i < index - 1; ++i)
            cur = cur->next;

        // Now, add the new node after this
        // and adjust the links
        Node *newNode = new Node(val);
        newNode->next = cur->next;

        // Update cur node's next as well
        // Also increment length
        cur->next = newNode;
        this->length += 1;
    }
    
    void deleteAtHead() {
        if(this->length == 0)
            return;

        Node *oldHead = this->head;

        this->head = head->next;
        this->length -= 1;

        delete oldHead;
    }
    
    void deleteAtIndex(int index) {
        if(index >= this->length)
            return;
        
        if(index == 0) {
            deleteAtHead();
            return;
        }
        
        Node *cur = this->head;
        for(int i = 0; i < index - 1; ++i)
            cur = cur->next;

        Node *uselessNode = cur->next;
        cur->next = cur->next->next;
        this->length -= 1;

        delete uselessNode;
    }
};

int main() {
	// your code goes here
	return 0;
}
