class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        Node* curr = head;
        while(curr){
            Node* copy = new Node(curr->val);
            Node* temp = curr->next;
            curr->next = copy;
            copy->next = temp;
            curr = temp;
        }
        
        curr = head;
        Node* copy = head->next;
        
        while(curr){
            if(curr->random) copy->random = curr->random->next;
            curr = copy->next;
            if(curr) copy = curr->next;
        }
        
        Node* ansHead = head->next;
        
        curr = head;
        copy = head->next;
        
        while(curr){
            curr->next = curr->next->next;
            if(curr->next) copy->next = copy->next->next;
            curr = curr->next;
            copy = copy->next;
        }
        
        return ansHead;
    }
};