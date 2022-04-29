class Solution {
public:
    int numTrees(int N) {
	    long long dp[N+1];
	    dp[0] = 1;
        dp[1] = 1;
	    for(int i=2;i<=N;i++){
	        long long sum = 0;
	        int low = 0,high = i-1;
	        
	        while(low < high) 
                sum += (2 * (dp[low++]*dp[high--]));
	        
	        if(low == high) sum += (dp[low] * dp[low]);
	        
	        dp[i] = sum;
	    }
	    return dp[N];        
    }
};