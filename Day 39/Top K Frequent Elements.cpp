#define pii pair<int,int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto &it : nums) mp[it]++;
        
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(auto it : mp){
            pq.push({it.second,it.first});
            if(pq.size() > k) pq.pop();
        }
        
        vector<int> ans;
        while(pq.size()){
            auto top = pq.top(); pq.pop();
            ans.push_back(top.second);
        }
        
        return ans;
    }
};