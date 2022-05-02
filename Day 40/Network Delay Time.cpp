class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto &it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int> dist(n+1,1e9);
        dist[0] = dist[k] = 0;
        
        queue<pair<int,int>> q; 
        q.push({k,0});
        while(q.size()){
            int sz = q.size();
            while(sz--){
                auto [node,prev] = q.front(); q.pop();
                for(auto &it : adj[node]){
                    int curr_time = prev + it.second;
                    if(dist[it.first] > curr_time){
                        dist[it.first] = curr_time;
                        q.push({it.first,curr_time});
                    }
                }
            }
        }
        
        int ans = 0;
        for(auto it : dist){
            if(it == 1e9) return -1;
            ans = max(ans,it);
        }
        return ans;
    }
};