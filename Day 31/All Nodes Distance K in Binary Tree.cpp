class Solution{
public:
    void kLevelDown(TreeNode* root,int level,int k,vector<int> &ans){
        if(!root) return;
        if(level == k) {ans.push_back(root->val); return;}
        kLevelDown(root->left,level+1,k,ans);
        kLevelDown(root->right,level+1,k,ans);
    }
    
    int kLevelUp(TreeNode* root,TreeNode* target,int k,vector<int> &ans){
        if(!root) return 0;
        
        if(root->val == target->val) return 1;
        
        int leftLevel = kLevelUp(root->left,target,k,ans);
        int rightLevel = kLevelUp(root->right,target,k,ans);
        
        if(leftLevel == k or rightLevel == k){
            ans.push_back(root->val);
            return k+1;
        }else if(leftLevel){
            kLevelDown(root->right,leftLevel+1,k,ans); 
            return leftLevel+1;
        }
        else if(rightLevel){
            kLevelDown(root->left,rightLevel+1,k,ans);
            return rightLevel+1;
        }
        
        return 0;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        int level = 0;
        kLevelDown(target,level,k,ans);
        if(k) kLevelUp(root,target,k,ans);
        return ans;
    }
};