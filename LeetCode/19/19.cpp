class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* pointer = head;
        ListNode* base = head;
        
        while(pointer) {
            pointer = pointer->next;
            size++;
        }
        
        if(size == n) {
            return base->next;
        }
        
        size = size - n - 1;
        
        while(size--) {
            base = base->next;
        }
        
        base->next = base->next->next;
        
        return head;
    }
};