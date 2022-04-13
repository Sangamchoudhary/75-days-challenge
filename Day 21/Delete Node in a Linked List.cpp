class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = node;
        while(node->next){
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }
        prev->next = NULL;
    }
};