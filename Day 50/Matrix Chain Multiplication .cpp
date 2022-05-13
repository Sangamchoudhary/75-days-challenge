class Solution{
public:
    int solve(int st,int en,int arr[],vector<vector<int>> &dp){
        if(st >= en) return 0;
        else if(dp[st][en] != -1) return dp[st][en];
        
        int mini = INT_MAX;
        
        for(int k=st;k<en;k++){
            int ans = solve(st,k,arr,dp) + solve(k+1,en,arr,dp) + (arr[st-1]*arr[k]*arr[en]);
            mini = min(mini,ans);
        }
        
        return dp[st][en] = mini;
    }

    int matrixMultiplication(int N, int arr[]){
        vector<vector<int>> dp(N+1,vector<int> (N+1,-1));
        return solve(1,N-1,arr,dp);
    }
};