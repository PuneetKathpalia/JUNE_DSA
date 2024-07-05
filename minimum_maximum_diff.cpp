// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */

// class Solution {
// public:
//     std::vector<int> nodesBetweenCriticalPoints(ListNode* head) {
//         // Positions of critical points
//         std::vector<int> criticalPoints;
        
//         // Position counter and pointers to traverse the list
//         int pos = 0;
//         ListNode* prev = nullptr;
//         ListNode* curr = head;
//         ListNode* next = head ? head->next : nullptr;
        
//         // Traverse the linked list
//         while (next != nullptr) {
//             if (prev != nullptr) {
//                 // Check if current node is a local minima or maxima
//                 if ((curr->val > prev->val && curr->val > next->val) || 
//                     (curr->val < prev->val && curr->val < next->val)) {
//                     criticalPoints.push_back(pos);
//                 }
//             }
//             // Move to the next node
//             prev = curr;
//             curr = next;
//             next = next->next;
//             pos++;
//         }
        
//         // If there are fewer than two critical points, return [-1, -1]
//         if (criticalPoints.size() < 2) {
//             return {-1, -1};
//         }
        
//         // Calculate minDistance and maxDistance
//         int minDistance = INT_MAX;
//         int maxDistance = criticalPoints.back() - criticalPoints.front();
        
//         for (size_t i = 1; i < criticalPoints.size(); ++i) {
//             minDistance = std::min(minDistance, criticalPoints[i] - criticalPoints[i - 1]);
//         }
        
//         return {minDistance, maxDistance};
//     }
// };