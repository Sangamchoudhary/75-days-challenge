class Solution {
public:
    int solve(TreeNode* root,bool &ans){
        if(!root) return 0;
        
        int lh = solve(root->left,ans);
        int rh = solve(root->right,ans);
        
        if(abs(lh-rh) > 1) ans = false;
        
        return 1 + max(lh,rh);
    }
    
    bool isBalanced(TreeNode *root){
        bool ans = true;
        solve(root,ans);
        return ans;
    }
};