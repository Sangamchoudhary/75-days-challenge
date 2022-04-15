class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;
        while(curr){
            if(curr->child){
                Node* temp = curr->next;
                Node* child_node = flatten(curr->child);
                curr->child = NULL;
                curr->next = child_node;
                child_node->prev = curr;
                while(curr->next) curr = curr->next;
                curr->next = temp;
                if(temp) temp->prev = curr;
                curr = temp;
            }else{
                curr = curr->next;
            }
        }
        return head;
    }
};