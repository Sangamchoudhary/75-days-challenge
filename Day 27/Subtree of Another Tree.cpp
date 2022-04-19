class Solution {
    void convert(TreeNode* node, string& s) {
        if (!node) {
            s.append("#");
            return;
        }
        s.append('*' + to_string(node->val) + '*');
        convert(node->left, s);
        convert(node->right, s);
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t){
        string s1, s2;
        convert(s, s1);
        convert(t, s2);
        return s1.find(s2) != string::npos;
    }
};