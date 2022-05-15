class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]){
        vector<int> ans;
        vector<bool> vis(V,false);
        
        queue<int> q;
        q.push(0);
        
        while(q.size()){
            int size = q.size();
            while(size--){
                int top = q.front(); q.pop();
                vis[top] = true;
                ans.push_back(top);
                for(int it : adj[top]){
                    if(!vis[it]){
                        vis[it] = true;
                        q.push(it);
                    }
                } 
            }
        }
        
        return ans;
    }
};