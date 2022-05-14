class Solution {
private:
    int dp[101][100001];
    
    int solve(int k,int n){
        if(n == 0 or n == 1 or k == 1) return n;
        if(dp[k][n] != -1) return dp[k][n];
        
        int mini = INT_MAX;
        int low = 0, high = n;
        
        while(low <= high){
            int mid = (low + high)/2;
            
            int down = solve(k-1,mid-1);
            int up = solve(k,n-mid);
            
            int ans = 1 + max(up,down);
            
            mini = min(mini,ans);
                
            if(down < up) low = mid + 1;
            else high = mid - 1;
        }
        
        return dp[k][n] = mini;
    }
public:
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof dp);
        return solve(k,n);
    }
};