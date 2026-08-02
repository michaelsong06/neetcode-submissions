/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        
        // Find the middle of the list
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Reverse second half of list
        
        ListNode* curr = slow->next;
        ListNode* prev = nullptr;
        slow->next = nullptr;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        
        ListNode* l = head;
        ListNode* r = prev;
        while (r) {
            ListNode* lTemp = l->next;
            ListNode* rTemp = r->next;
            l->next = r;
            r->next = lTemp;
            l = lTemp;
            r = rTemp;
        }
        
    }
};
