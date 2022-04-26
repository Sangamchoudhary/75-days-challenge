class Solution {
private:
    int sum = 0;
public:
    void dfs(TreeNode* root, int L, int R){
        if(!root) return;
        if(root->val >= L && root->val <= R) sum += root->val;
		if(root->val > L) dfs(root->left,L,R);
        if(root->val < R) dfs(root->right,L,R);
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        dfs(root,L,R);
        return sum;
    }
};