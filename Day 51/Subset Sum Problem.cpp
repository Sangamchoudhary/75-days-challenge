class Solution{   
public:
    int dp[101][10001];
    bool solve(int i,int arr[],int sum,int N){
        if(sum == 0){
            return true;
        }else if(sum < 0){
            return false;
        }else if(i == N){
            return false;
        }else if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        
        bool result = false;
        if(arr[i] <= sum){
            result = solve(i+1,arr,sum-arr[i],N) or solve(i+1,arr,sum,N);
        }else{
            result = solve(i+1,arr,sum,N);
        }
        
        return dp[i][sum] = result;
    }
    bool isSubsetSum(int N, int arr[], int sum){
        memset(dp,-1,sizeof dp);
        return solve(0,arr,sum,N); 
    }
};