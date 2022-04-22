class Solution {
public:
    int widthOfBinaryTree(TreeNode* root){
        if(!root) return 0;
        long long ans = 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int n = q.size();
            long long first,last;
            long long mini = q.front().second;
            for(int i=0;i<n;i++){
                auto node = q.front().first;
                
                long long x = q.front().second - mini;
                q.pop();
                
                if(i == 0) first = x;
                if(i == n-1) last = x;
                
                if(node->left) q.push({node->left,2*x+1});
                if(node->right) q.push({node->right,2*x+2});
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};