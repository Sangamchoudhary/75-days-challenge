class Solution {
public:
    ListNode *getIntersectionNode(ListNode *rootA, ListNode *rootB) {
        ListNode* headA = rootA, *headB = rootB;
        unordered_set<ListNode*> st;
        
        while(headA){
            st.insert(headA);
            headA = headA->next;
        }
        
        while(headB){
            auto ele = headB;
            
            if(st.find(ele) != st.end()) return headB;
            
            headB = headB->next;
        }
        
        return NULL;
    }
};