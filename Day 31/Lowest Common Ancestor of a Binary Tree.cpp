class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root or root == p or root == q){
            return root;
        }
        auto left = lowestCommonAncestor(root->left,p,q);
        auto right =lowestCommonAncestor(root->right,p,q);
        if(!left) return right;
        else if(!right) return left;
        else return root;
    }
};