class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int j = 0,ans = 0,n = arr.size(),sum = 0;
        while(j < n){
            sum += arr[j];
            int rem = sum % k;
            if(rem < 0) rem += k;
            ans += mp[rem];   
            mp[rem]++;
            j++;
        }
        return ans;        
    }
};