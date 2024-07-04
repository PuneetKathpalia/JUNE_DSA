#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node * constructLL(vector<int> &arr){
    Node * head=new Node(arr[0]);
    Node * prev = head;
    for(int i=1;i<arr.size();i++){
        Node * temp = new Node(arr[i],nullptr, prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

void print(Node * head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node* removesHead(Node *head) {
    if (head == nullptr) return head;
    Node *temp = head;
    head = head->next;
    if (head != nullptr) {
        head->back = nullptr;
    }
    delete temp;
    return head;
}

Node* removesTail(Node *head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->back->next = nullptr;
    delete temp;
    return head;
}

Node* removesK(Node* head, int k) {
    if (head == nullptr) return head;
    if (k == 1) {
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->back = nullptr;
        }
        delete temp;
        return head;
    }
    int count = 1;
    Node* temp = head;
    while (temp != nullptr && count < k) {
        temp = temp->next;
        count++;
    }
    if (temp == nullptr) return head;
    if (temp->back != nullptr) {
        temp->back->next = temp->next;
    }
    if (temp->next != nullptr) {
        temp->next->back = temp->back;
    }
    delete temp;
    return head;
}

Node* removesV(Node* head, int v) {
    if (head == nullptr) return head;
    if (head->data == v) {
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->back = nullptr;
        }
        delete temp;
        return head;
    }
    Node* temp = head;
    while (temp != nullptr && temp->data != v) {
        temp = temp->next;
    }
    if (temp == nullptr) return head;
    if (temp->back != nullptr) {
        temp->back->next = temp->next;
    }
    if (temp->next != nullptr) {
        temp->next->back = temp->back;
    }
    delete temp;
    return head;
}

int main() {
    vector<int> arr = {12, 5, 8, 7};
    Node *head = constructLL(arr);
    head=removesTail(head);
    print(head);
    return 0;
}