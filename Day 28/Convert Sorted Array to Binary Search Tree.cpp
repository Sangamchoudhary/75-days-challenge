class Solution {
public:
    TreeNode* makeBst(int i,int j,vector<int> &nums){
        if(i > j) return NULL;
        
        int mid = (i+j)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = makeBst(i,mid-1,nums);
        root->right = makeBst(mid+1,j,nums);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return makeBst(0,n-1,nums);
    }
};