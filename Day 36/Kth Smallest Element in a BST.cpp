class Solution {
public:
    void dfs(TreeNode* root,int &count,int k,int &ans){
        if(!root) return;
        dfs(root->left,count,k,ans);
        count++;
        if(count == k) ans = root->val;
        dfs(root->right,count,k,ans);
    }
    
    int kthSmallest(TreeNode* root, int k){
        int count = 0,ans = 0;
        dfs(root,count,k,ans);
        return ans;
    }
};