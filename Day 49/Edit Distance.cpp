class Solution {
public:
    int dp[501][501];
    int solve(string s1,int m,string s2,int n){
        if(m < 0) return n+1;
        if(n < 0) return m+1;
        if(dp[m][n] != -1) return dp[m][n];
        
        if(s1[m] == s2[n]) 
            return dp[m][n] = solve(s1,m-1,s2,n-1);
        
        int insert = solve(s1,m,s2,n-1);
        int remove = solve(s1,m-1,s2,n);
        int replace = solve(s1,m-1,s2,n-1);
        
        int ans = 1 + min({insert,remove,replace});
        return dp[m][n] = ans;
    }
    int minDistance(string s1, string s2){
        int m = s1.size(), n = s2.size();
        memset(dp,-1,sizeof dp);
        return solve(s1,m-1,s2,n-1);
    }
};