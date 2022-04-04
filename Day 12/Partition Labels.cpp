class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++) mp[s[i]] = i;
        
        vector<int> ans;
        
        int max_far = -1, prev = -1;
        
        for(int i=0;i<n;i++){
            int curr_far = mp[s[i]];
            max_far = max(max_far,curr_far);
            
            if(i == max_far){
                ans.push_back(i - prev);
                prev = i;
            }
        }
        
        return ans;
    }
};