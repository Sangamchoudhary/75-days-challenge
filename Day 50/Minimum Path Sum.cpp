class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>> &grid,vector<vector<int>>&dp){
        if(i == m-1 and j == n-1) return grid[i][j];
        else if(dp[i][j] != -1) return dp[i][j];
        
        int down = INT_MAX, right = INT_MAX;
        
        if(i+1 < grid.size())    down = solve(i+1,j,m,n,grid,dp);
        
        if(j+1 < grid[0].size()) right = solve(i,j+1,m,n,grid,dp);
        
        int ans = grid[i][j] + min(down,right);
        return dp[i][j] = ans;
    }
    int minPathSum(vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solve(0,0,m,n,grid,dp);
    }
};