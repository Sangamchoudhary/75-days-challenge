class Solution {
public:
    void merge(TreeNode* r1,TreeNode* r2,TreeNode* &head){
        head = new TreeNode();
        
        if(r1 and r2) {head->val = r1->val + r2->val;}
        else if(!r2)  {head = r1; return;}
        else if(!r1)  {head = r2; return;}
        
        merge(r1->left,r2->left,head->left);
        merge(r1->right,r2->right,head->right);
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        else if(!root2) return root1;
        TreeNode* head = new TreeNode(root1->val + root2->val);
        TreeNode* curr = head;
        merge(root1->left,root2->left,curr->left);
        merge(root1->right,root2->right,curr->right);
        return head;
    }
};