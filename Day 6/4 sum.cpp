class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int sum = target - (nums[i] + nums[j]);
                int k = j+1,l=n-1;
                while(k<l){
                    if(nums[k] + nums[l] == sum){
                        vector<int> v = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(v);
                        k++; l--;
                        while(k<l && nums[k]==v[2]) ++k;
                        while(k<l && nums[l]==v[3]) --l;
                    }
                    else if(nums[k] + nums[l] < sum){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
                while(i+1<n-3 && nums[i+1]==nums[i]) i++;
                while(j+1<n-2 && nums[j+1]==nums[j]) j++;
            }
        }
        return ans;
    }
};