class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        while(n-- >= 0){
            if(!curr) return head->next;
            curr = curr->next;
        }
        
        ListNode* root = head;
        while(curr) root = root->next, curr = curr->next;
        
        root->next = root->next->next;
        return head;
    }
};