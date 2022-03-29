class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> mp;
        int ans = 0;
        
        for(auto &it : time){
            int rem = it % 60;
            
            if(rem == 0) ans += mp[0];
            
            else ans += mp[60 - rem];
            
            mp[rem]++;
        }
        
        return ans;
    }
};