class Solution {
private:
    int count = 0;
public:
    void dfs(TreeNode* root,int sum,int ts,unordered_map<int,int> mp){
        if(!root) return;
        sum += root->val;
        if(mp.find(sum - ts) != mp.end()) count += mp[sum-ts] ;
        mp[sum]++;
        dfs(root->left,sum,ts,mp);
        dfs(root->right,sum,ts,mp);
    }
    int pathSum(TreeNode* root, int ts){
        unordered_map<int,int> mp;
        mp[0] = 1;
        dfs(root,0,ts,mp);
        return count;
    }
};