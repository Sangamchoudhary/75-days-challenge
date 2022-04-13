class Solution {
public:
    bool palindromeCheck(ListNode* head1, ListNode* head2){
        while(head1 and head2){
            if(head1-> val != head2->val) return false;
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode* root){
        ListNode* prev = NULL;
        ListNode* curr = root;
        
        while(curr){
            ListNode* Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = head;
        slow = reverse(slow);
        
        bool check = palindromeCheck(slow,fast);
        
        return check;
    }
};