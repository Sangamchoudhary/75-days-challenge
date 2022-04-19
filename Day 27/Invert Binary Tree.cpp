class Solution {
public:    
    void dfs(TreeNode* &root){
        if(!root) return;
        if(root->left or root->right) {
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        dfs(root->left);
        dfs(root->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};