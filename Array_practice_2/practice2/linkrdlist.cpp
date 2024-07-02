#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
    Node(int x, Node* nextNode) {
        data = x;
        next = nextNode;
    }
};

void print(Node *head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* constructLL(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* insertHead(Node* head, int v) {
    Node* temp = new Node(v, head); 
    return temp;
}

Node* insertTail(Node* head, int v) {\
    if (head == nullptr) {
        return new Node(v);
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new Node(v);
    return head;
}

Node* insertAtK(Node* head, int v, int k) {
    if (head == nullptr && k == 1) {
        return new Node(v);
    }
    if (k == 1) {
        Node* newHead = new Node(v, head);
        return newHead;
    }
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        if (count == (k - 1)) {
            Node* newNode = new Node(v, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node* insertBeforeValue(Node* head, int v, int target) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->data == target) {
        return new Node(v, head);
    }
    
    Node* temp = head;
    while (temp->next != nullptr) {
        if (temp->next->data == target) {
            Node* newNode = new Node(v, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    
    return head;
}


int main() {
    vector<int> arr = {12, 5, 8, 7};
    Node *head = constructLL(arr);
    head = insertBeforeValue(head, 100,8);
    print(head);
    return 0;
}