class Solution {
private:
    unordered_map<int,int> mp;
    
    TreeNode* solve(vector<int> &preorder,int pre_start,int pre_end,vector<int> &postorder,int post_start,int post_end){
        if(pre_start > pre_end or post_start > post_end) return NULL;
        
        TreeNode* root = new TreeNode(preorder[pre_start]);
        
        if(pre_start + 1 <= pre_end){
            int curr_pos = mp[preorder[pre_start + 1]];
            int num_left = curr_pos - post_start + 1;
            
            root->left = solve(preorder,pre_start+1,pre_start + num_left,postorder,post_start,curr_pos);
            root->right = solve(preorder,pre_start+num_left+1,pre_end,postorder,curr_pos+1,post_end-1);
        }
        
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        
        for(int i=0;i<postorder.size();i++){
            mp[postorder[i]] = i;
        }
        
        return solve(preorder,0,n-1,postorder,0,n-1);
    }
};