class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int len = 0;
        ListNode* temp1 = head;
        while(temp1) temp1 = temp1->next,len++;
        
        k %= len;
        
        if(k == 0) return head;
        
        ListNode* curr = head, *newCurr = head;
        
        while(curr and k--) curr = curr->next;
        
        while(curr->next) newCurr = newCurr->next, curr = curr->next;
        
        ListNode* temp = newCurr; 
        newCurr = newCurr->next;
        temp->next = NULL;
        
        ListNode* last = newCurr;
        
        while(last->next) last = last->next;
        
        last->next = head;
        
        return newCurr;
    }
};