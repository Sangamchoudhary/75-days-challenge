class Solution {
private:
    int sum = 0;
public:
    void solve(TreeNode* root,int dir){
        if(!root) return;
        if(!root->left and !root->right){
            if(dir == 1) sum += root->val;
            return;
        }
        solve(root->left,1);
        solve(root->right,2);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        solve(root,0);
        return sum;
    }
};