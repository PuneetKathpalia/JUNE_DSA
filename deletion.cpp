#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
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

Node* removesHead(Node *head) {
    if (head == nullptr) return head;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* removesTail(Node *head) {
    if (head == nullptr || head->next==nullptr ) return nullptr;
    Node * temp=head;
    while (temp-> next-> next !=nullptr){
        temp=temp->next;
    }
    delete temp-> next;
    temp-> next=nullptr;
    return head;
}

Node * removesK(Node * head,int k){
    if(head==nullptr) return head;
    if(k==1){
        Node * temp =head;
        head=head->next;
        free(temp);
        return head;
    } 
    int count=0;
    Node * temp=head;
    Node * prev =nullptr;
    while(temp!=nullptr){
        count++;
        if(count==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

Node * removesV(Node * head,int v){
    if(head==nullptr) return head;
    if(head-> data==v){
        Node * temp =head;
        head=head->next;
        free(temp);
        return head;
    }
    Node * temp=head;
    Node * prev =nullptr;
    while(temp!=nullptr){
        if(temp->data==v){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
 
int main() {
    vector<int> arr = {12, 5, 8, 7};
    Node *head = constructLL(arr);
    head = removesV(head,8);
    print(head);
    return 0;
}