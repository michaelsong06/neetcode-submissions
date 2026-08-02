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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* cursor1 = list1;
        ListNode* cursor2 = list2;

        ListNode* output = new ListNode();
        ListNode* outputCursor = output;

        while (cursor2 || cursor1) {
            if (!cursor1) {
                outputCursor->next = cursor2;
                cursor2 = cursor2->next;
            } else if (!cursor2) {
                outputCursor->next = cursor1;
                cursor1 = cursor1->next;
            } else {
                if (!cursor2 || cursor1->val <= cursor2->val) {
                outputCursor->next = cursor1;
                cursor1 = cursor1->next;
                } else {
                    outputCursor->next = cursor2;
                    cursor2 = cursor2->next;
                }
            }
            
            outputCursor = outputCursor->next;
        }

        outputCursor = output->next;
        delete(output);
        return outputCursor;
    }
};
