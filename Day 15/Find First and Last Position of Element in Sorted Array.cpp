class Solution {
public:
    int lowerBound(vector<int>& nums, int target){
        
        int n = nums.size();
        int i=0,j=n-1;
        int ans = -1;
        int mid;
        while(i <= j){
            mid = i + ((j-i)/2);
            
            if(nums[mid] < target){
                i = mid+1;
            }else if(nums[mid] > target){
                j = mid-1;
            }else{
                ans = mid;
                j = mid-1;
            }
        }
        return ans;
    }    
    
    int upperBound(vector<int>& nums, int target){
        
        int n = nums.size();
        int i=0,j=n-1;
        
        int ans = -1;
        int mid;
        while(i <= j){
            mid = i + ((j-i)/2);
            
            if(nums[mid] < target){
                i = mid+1;
            }else if(nums[mid] > target){
                j = mid-1;
            }else{
                ans = mid;
                i = mid+1;
            }
        }
        return ans;
    }    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int lb = lowerBound(nums,target);
        int ub = upperBound(nums,target);
        
        return {lb,ub};
    }
};