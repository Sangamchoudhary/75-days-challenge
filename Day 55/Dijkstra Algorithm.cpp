class Solution{
	public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int src){
        vector<int> dist(V,1e9);
        
        priority_queue<pair<int,int>> pq;
        pq.push({0,src});
        dist[src] = 0;
        
        while(pq.size()){
            auto top = pq.top(); pq.pop();
            int prev_dist = top.first;
            int node = top.second;
            
            for(auto &it : adj[node]){
                int curr_dist = prev_dist + it[1];
                if(curr_dist < dist[it[0]]){
                    dist[it[0]] = curr_dist;
                    pq.push({curr_dist,it[0]});
                }
            }
        }
        
        return dist;
    }
};