class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target){
        sort(nums.begin(),nums.end());
        int i = 0, n = nums.size(), mini_diff = 1e9, ans;
        while(i < n-2){
            int j = i + 1,k = n - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                int abs_diff = abs(target - sum);
                
                if(abs_diff < mini_diff){
                    mini_diff = abs_diff;
                    ans = sum;
                }
                
                if(sum > target) k--;
                else if(sum < target) j++;
                else return target;
            }
            i++;
        }
        return ans;
    }
};