class Solution {
private:
    TreeNode *node_1 = NULL, *node_2 = NULL, *prev = NULL;
public:
    void recoverTree(TreeNode* root) {
        if (!root) return;

        inorder(root);
        if (node_1 && node_2) 
            swap(node_1->val, node_2->val);
    }

    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root->left);
        if (prev && root->val < prev->val){
            if (!node_1) node_1 = prev;
            if (node_1) node_2 = root;
        }
        prev = root;
        inorder(root->right);
    }
};