class Solution {
public:
    bool solve(TreeNode* p,TreeNode* q){
        if(!p and !q) return true;
        if(!p or !q) return false;
        
        if(p->val != q->val) return false;
        
        return solve(p->left,q->left) and solve(p->right,q->right);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p,q);
    }
};