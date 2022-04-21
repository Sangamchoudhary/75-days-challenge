class Solution {
public:
    bool hasPathSum(TreeNode* root, int ts) {
        if(!root) return false;
        if(!root->left and !root->right){
            ts -= root->val;
            if(!ts) return true;
            return false;
        }
        bool ls = hasPathSum(root->left,ts - root->val);
        bool rs = hasPathSum(root->right,ts - root->val);
        return ls or rs;
    }
};