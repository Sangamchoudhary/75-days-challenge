class Solution {
public:
    int maxProfit(vector<int>& arr) {
        // int b1 = INT_MIN, s1 = 0, b2 = INT_MIN, s2 = 0;
        // for (int p  : arr) {
        //     b1 = max(b1, -p);
        //     s1 = max(s1, b1 + p);
        //     b2 = max(b2, s1 - p);
        //     s2 = max(s2, b2 + p);
        // }
        // return s2;
        int n = arr.size();
        int ans = 0;
        int left[n];
        int mn = arr[0];
        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,arr[i] - mn > 0 ? arr[i] - mn : 0);
            left[i] = maxi;   
            mn = min(mn,arr[i]);
        }
        int mx = arr[n-1];
        for(int i=n-1;i>=0;i--){
            int right = mx - arr[i]  > 0 ? mx - arr[i] : 0;
            ans = max(ans,left[i] + right);
            mx = max(mx,arr[i]);
        }
        return ans;
    }
};