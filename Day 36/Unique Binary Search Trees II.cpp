class Solution {
public:  
    vector<TreeNode*> solve(int st,int en){
        if(st > en) return {NULL};
        vector<TreeNode*> ans;
        for(int i=st;i<=en;i++){
            vector<TreeNode*> left = solve(st,i-1);
            vector<TreeNode*> right = solve(i+1,en);
            for(auto l : left){
                for(auto r : right){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }        
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n){
        return solve(1,n);   
    }
};