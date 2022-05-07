    void solve(int i,int j,string temp,vector<string> &ans,vector<vector<int>> &m, int &n,vector<vector<int>> vis){
        
        if(i < 0 or i > n-1 or j < 0 or j > n-1 or m[i][j] == 0){
            return;
        }else if(vis[i][j]){
            return;
        }
        
        if(i == n-1 and j == n-1){
            ans.push_back(temp);
            return;
        }
        
        vis[i][j] = 1;
        solve(i-1,j,temp+'U',ans,m,n,vis);
        solve(i,j-1,temp+'L',ans,m,n,vis);
        solve(i,j+1,temp+'R',ans,m,n,vis);
        solve(i+1,j,temp+'D',ans,m,n,vis);
        vis[i][j] = 0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis( n , vector<int> (n, 0));
        string temp;
        solve(0,0,temp,ans,m,n,vis);
        sort(ans.begin(),ans.end());
        return ans;
    }