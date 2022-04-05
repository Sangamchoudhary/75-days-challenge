class Solution {
public:
    int helper(vector<int>& nums, int k)
    {
        unordered_map<int,int> mp;
        int n = nums.size();
        int i=0;
        int unique=0;//unique no till the current window
        int ans=0;
        for(int j=0; j<n; j++)
        {
            int curr = nums[j];
            if(mp.find(curr) == mp.end())
                unique++;
            
            mp[curr]++;
            
            while(unique > k)
            {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)
                {
                    mp.erase(nums[i]);
                    unique--;
                }
                
                i++;
            }
            ans += j-i+1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        return helper(nums,k) - helper(nums, k-1);
    }
};