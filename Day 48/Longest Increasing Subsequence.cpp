class Solution {
public:
    int lengthOfLIS(vector<int>& arr){
        int n = arr.size();
        vector<int> dp;
        for(int i=0;i<n;i++){
            int val = arr[i];
            
            int lb = lower_bound(dp.begin(),dp.end(),val) - dp.begin();
            
            if(lb < dp.size())
                dp[lb] = min(dp[lb],val);
            else
                dp.push_back(val);
        }
        return dp.size();
    }
};