class Solution {
  public:
    
    void dfs(int ele,vector<int> adj[],vector<int> &ans,vector<bool> &vis){
        vis[ele] = true;
        for(auto it : adj[ele]){
            if(!vis[it]){
                vis[it] = true;
                ans.push_back(it);
                dfs(it,adj,ans,vis);
            }
        }
    }
  
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> vis(V,false);
        ans.push_back(0);
        dfs(0,adj,ans,vis);
        return ans;
    }
};