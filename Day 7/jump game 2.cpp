class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int step = 0;
        int curr_far, max_so_far = 0, n = nums.size();
        int maxi=0;
        
        for(int i=0;i<n;i++){
            curr_far = i + nums[i];
            
            maxi = max(maxi,curr_far);
            
            if(max_so_far == i){
                max_so_far = maxi;
                step++;
            }
            
            if(max_so_far >= n-1) break;
        }
        
        return step;
    }
};