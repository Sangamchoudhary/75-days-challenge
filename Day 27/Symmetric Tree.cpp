class Solution {
public:
    
    bool solve(TreeNode* left,TreeNode* right){
        if(!left or !right){
            return left == right;
        }
        if(left->val != right->val){
            return false;
        }
        return solve(left->left,right->right) and solve(left->right,right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return solve(root->left,root->right);
    }
};