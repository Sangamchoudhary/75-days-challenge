class Solution {
public:   
    void bfs(queue<TreeNode*> &q,int size,vector<vector<int>> &ans,int flag){
        vector<int> temp;
        while(size--){
            auto node = q.front();
            temp.push_back(node->val);
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        if(flag) reverse(temp.begin(),temp.end());
        ans.push_back(temp);
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int flag = 1;
        while(!q.empty()){
            int size = q.size();
            flag = !flag;
            bfs(q,size,ans,flag);
        }
        return ans;
    }
};