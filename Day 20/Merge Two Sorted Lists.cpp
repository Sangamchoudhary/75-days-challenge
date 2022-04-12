class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* root = new ListNode();
        ListNode* head = root;
        
        while(list1 and list2){
            if(list1->val >= list2->val){
                head->next = new ListNode(list2->val);
                head = head->next;
                list2 = list2->next;
            }else{
                head->next = new ListNode(list1->val);
                head = head->next;
                list1 = list1->next;                
            }
        }
        
        if(list1) head->next = list1;
        if(list2) head->next = list2;
        
        return root->next;
    }
};
In-place

class Solution {
public:
    void solve(ListNode* &list1,ListNode* &list2){
        ListNode* prev;
        while(list1 and list1->val <= list2->val){
            prev = list1;
            list1 = list1->next;
        }        
        prev->next = list2;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        
        ListNode* head = (list1->val <= list2->val) ? list1 : list2;
        
        while(list1 and list2){
            if(list1 and list1->val <= list2->val)
                solve(list1,list2);
            else
                solve(list2,list1);
        }        
        
        return head;
    }
};