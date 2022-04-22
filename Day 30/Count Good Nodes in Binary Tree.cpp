class Solution {
private:
    int ans = 0;
    void solve(TreeNode* root,int maxi){
        if(!root) return;
        if(maxi <= root->val) ans++;
        maxi = max(maxi,root->val);
        solve(root->left,maxi);
        solve(root->right,maxi);
    }
public:
    int goodNodes(TreeNode* root) {
        solve(root,-1e9);
        return ans;
    }
};