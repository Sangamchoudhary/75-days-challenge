class Solution {
private:
    int mini = 1e9, prev = -1;
public:
    void solve(TreeNode* root){
        if(!root) return;
        solve(root->left);
        if(prev != -1) 
            mini = min(mini,abs(root->val - prev));
        prev = root->val;
        solve(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        solve(root);
        return mini;
    }
};