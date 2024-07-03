// #include <bits/stdc++.h>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* next;
//     Node* back;

//     Node(int data1, Node* next1, Node* back1) {
//         data = data1;
//         next = next1;
//         back = back1;
//     }

//     Node(int data1) {
//         data = data1;
//         next = nullptr;
//         back = nullptr;
//     }
// };

// void print(Node *head) {
//     while (head != nullptr) {
//         cout << head->data << " ";
//         head = head->next;
//     }
//     cout << endl;
// }

// Node* constructDLL(vector<int>& arr) {
//     if (arr.empty()) return nullptr;
//     Node *head = new Node(arr[0]);
//     Node *mover = head;
//     for (int i = 1; i < arr.size(); i++) {
//         Node *temp = new Node(arr[i]);
//         mover->next = temp;
//         temp->back = mover;
//         mover = temp;
//     }
//     return head;
// }

// Node* insertHead(Node* head, int v) {
//     Node* temp = new Node(v, head);
//     if (head != nullptr) {
//         head->back = temp;
//     }
//     return temp;
// }

// Node* insertTail(Node* head, int v) {
//     if (head == nullptr) {
//         return new Node(v);
//     }
//     Node* temp = head;
//     while (temp->next != nullptr) {
//         temp = temp->next;
//     }
//     Node* newNode = new Node(v);
//     temp->next = newNode;
//     newNode->back = temp;
//     return head;
// }

// Node* insertAtK(Node* head, int v, int k) {
//     if (head == nullptr && k == 1) {
//         return new Node(v);
//     }
//     if (k == 1) {
//         Node* newHead = new Node(v, head);
//         if (head != nullptr) {
//             head->back = newHead;
//         }
//         return newHead;
//     }
//     int count = 0;
//     Node* temp = head;
//     while (temp != nullptr) {
//         count++;
//         if (count == (k - 1)) {
//             Node* newNode = new Node(v, temp->next, temp);
//             if (temp->next != nullptr) {
//                 temp->next->back = newNode;
//             }
//             temp->next = newNode;
//             break;
//         }
//         temp = temp->next;
//     }
//     return head;
// }

// Node* insertBeforeValue(Node* head, int v, int target) {
//     if (head == nullptr) {
//         return nullptr;
//     }
//     if (head->data == target) {
//         Node* newHead = new Node(v, head);
//         head->back = newHead;
//         return newHead;
//     }
//     Node* temp = head;
//     while (temp->next != nullptr) {
//         if (temp->next->data == target) {
//             Node* newNode = new Node(v, temp->next, temp);
//             temp->next->back = newNode;
//             temp->next = newNode;
//             break;
//         }
//         temp = temp->next;
//     }
//     return head;
// }

// int main() {
//     vector<int> arr = {12, 5, 8, 7};
//     Node *head = constructLL(arr);
    
//     print(head);
//     return 0;
// }