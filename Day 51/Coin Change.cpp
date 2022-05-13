class Solution {
public:
    int dp[13][10001];
    int solve(vector<int>&coins,int currAmount,int amount,int n){
        if(currAmount > amount)  return INT_MAX-1;
        else if(currAmount == amount) return 0;
        else if(n < 0) return INT_MAX-1;
        else if(dp[n][currAmount] != -1) return dp[n][currAmount];
        
        int op1 = INT_MAX,op2 = INT_MAX;
        
        op1 = 1 + solve(coins,currAmount + coins[n],amount,n);
        
        op2 = solve(coins,currAmount,amount,n-1);
        
        return dp[n][currAmount] = min(op1,op2);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(dp,-1,sizeof dp);
        int ans = solve(coins,0,amount,n-1);
        if(ans == INT_MAX-1) return -1;
        return ans;
    }
};