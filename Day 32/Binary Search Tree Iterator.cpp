class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        auto it = st.top();
        st.pop();
        int ans = it->val;
        it = it->right;
        while(it){
            st.push(it);
            it = it->left;
        }
        return ans;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};