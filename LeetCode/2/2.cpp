class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* last = ans;
        bool carry = false;
        int sum = 0;
        
        while(l1 && l2) {
            if(carry) {
                sum = l1->val + l2->val + 1;    
            }
            else {
                sum = l1->val + l2->val;
            }
            
            carry = false;
            
            if(sum >= 10) {
                carry = true;
                sum -= 10;
            }
            
            last->next = new ListNode(sum);
            last = last->next;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        
        while(l1) {
            if(carry) {
                sum = l1->val + 1;
            }
            else {
                sum = l1->val;
            }
            
            carry = false;
            
            if(sum >= 10) {
                carry = true;
                sum -= 10;
            }
            
            last->next = new ListNode(sum);
            last = last->next;
            
            l1 = l1->next;
        }
        
        while(l2) {
            if(carry) {
                sum = l2->val + 1;
            }
            else {
                sum = l2->val;
            }
            
            carry = false;
            
            if(sum >= 10) {
                carry = true;
                sum -= 10;
            }
            
            last->next = new ListNode(sum);
            last = last->next;
            
            l2 = l2->next;
        }
        
        if(carry) {
            last->next = new ListNode(1);
        }
        
        return ans->next;
    }
};