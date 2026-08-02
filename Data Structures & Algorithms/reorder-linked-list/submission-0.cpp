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
        
        ListNode* l = head;
        ListNode* r = head;
        while (r->next) r = r->next;

        ListNode* temp = (head->next) ? head->next : nullptr;

        while (l != r) {
            l->next = r;
            l = temp;
            r->next = temp;
            while (temp->next != r) temp = temp->next;
            r = temp;
            temp = l->next;
        }
        l->next = nullptr;
    }
};
