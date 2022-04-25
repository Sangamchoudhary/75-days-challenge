class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        while(q.size()){
            Node* prev = NULL;
            int sz = q.size();
            while(sz--){
                auto node = q.front(); q.pop();
                
                if(prev) prev->next = node;
                prev = node;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return root;
    }
};