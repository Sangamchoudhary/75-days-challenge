class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int RGE = arr[n-1];
        int ans = INT_MIN;
        
        for(int i=n-1;i>=0;i--){
            if( arr[i] >= RGE ){
                RGE = arr[i];
            }
            ans = max( ans,RGE - arr[i] );
        }
        return ans;
    }
};