class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        ListNode* lastPosition = result;
        
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                lastPosition->next = l1;
                l1 = l1 -> next;
            }
            else {
                lastPosition->next = l2;
                l2 = l2 -> next;
            }
            lastPosition = lastPosition->next;
        }
        
        lastPosition->next = l1 ? l1 : l2;
        return result->next;
    }
};