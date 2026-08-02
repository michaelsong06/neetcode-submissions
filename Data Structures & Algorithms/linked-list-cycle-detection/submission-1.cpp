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
    bool hasCycle(ListNode* head) {
        
        ListNode* fastCursor = head;
        ListNode* slowCursor = head;

        while (fastCursor->next && fastCursor->next->next) {
            fastCursor = fastCursor->next->next;
            slowCursor = slowCursor->next;

            if (fastCursor == slowCursor) return true;
        }

        return false;
    }
};
