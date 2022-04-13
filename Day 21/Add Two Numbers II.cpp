class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* master = new ListNode();
        ListNode* root = master;
        
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        int carry = 0;
        
        while(l1 and l2){
            
            int val1 = l1->val; l1 = l1->next; 
            int val2 = l2->val; l2 = l2->next;
            
            int sum = val1 + val2 + carry;
            
            int num = sum % 10;  
            sum /= 10; 
            carry = sum;
            
            root->next = new ListNode(num);
            root = root->next;
        }
        
        while(l1){
            int val1 = l1->val; l1 = l1->next;
            
            int sum = val1 + carry;
            
            int num = sum % 10;  
            sum /= 10; 
            carry = sum;
            cout<<num;
            root->next = new ListNode(num);
            root = root->next;            
        }
        
        while(l2){
            int val = l2->val; l2 = l2->next;
            
            int sum = val + carry;
            
            int num = sum % 10;  
            sum /= 10; 
            carry = sum;
            
            root->next = new ListNode(num);
            root = root->next;                        
        }
        
        if(carry){
            root->next = new ListNode(carry);
            root = root->next;
        }
        
        master = reverse(master->next);
        return master;
    }
};