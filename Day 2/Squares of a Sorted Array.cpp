class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int start=0;
        int end=n-1;
        
        vector <int> ans(n);
        int pos = n-1;
        
        while(start <= end)
        {
            if(abs(nums[start]) < abs(nums[end])) {
                ans[pos--] = nums[end] * nums[end];
                end--;
            } else{
                ans[pos--] = nums[start] * nums[start];
                start++;
            }
        }
        
        return ans;
    }
};