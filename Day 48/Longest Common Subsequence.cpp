class Solution{
public:
    int dp[1001][1001];
    int solve(string &s1,int n1,string &s2,int n2){
        if(n1 < 0 or n2 < 0) return 0;
        else if(dp[n1][n2] != -1) return dp[n1][n2];
            
        int op1 = 0;
        if(s1[n1] == s2[n2]) op1 = 1 + solve(s1,n1-1,s2,n2-1);
        int op2 = solve(s1,n1-1,s2,n2);
        int op3 = solve(s1,n1,s2,n2-1);
        
        return dp[n1][n2] = max({op1,op2,op3});
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        memset(dp,-1,sizeof dp);
        return solve(s1,n1-1,s2,n2-1);
    }
};