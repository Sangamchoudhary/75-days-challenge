class Solution {
public:
    ListNode* reverse(ListNode* head,int k){
        int kk = k, count = 0;
        
        ListNode* curr = head;
        while(curr and count <= k) curr = curr->next, count++;
        if(count < k) return head;
        
        ListNode* last = head;
        ListNode* prev = head;
        while(head and kk--){
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        
        last->next = reverse(head,k);
        
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverse(head,k);        
    }
};