class Solution {
public:
    void recur(TreeNode* root,string path, vector<string>& ans){
        if(!root) return;
        if(!root->left and !root->right){
            path += to_string(root->val);
            ans.push_back(path);
            return;
        }
        recur(root->left,path + to_string(root->val) + "->",ans);
        recur(root->right,path + to_string(root->val) + "->",ans);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        recur(root,"",ans);
        return ans;
    }
};