class Solution {
public:
    int solve(TreeNode* root , int &res){
        if(!root){
            return 0;
        }
        int ld = solve(root->left,res);
        int rd = solve(root->right,res);
        res = max(res,ld + rd);
        return 1 + max(ld,rd);
    }    
    
    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN;
        solve(root,res);
        return res;        
    }
};