    bool isSubsetSum(int arr[],int N,int sum){
        
        bool t[N+1][sum+1];
        
    
    for(int i=0;i<=N;i++)
    for(int j=0;j<=sum;j++){
        
        if(i==0)
        t[i][j]=false;
        if(j==0)
        t[i][j]=true;
    }
        
    for(int i=1;i<=N;i++)
    for(int j=1;j<=sum;j++){
        
        if(arr[i-1]<=j)
        t[i][j]=t[i-1][j-arr[i-1]] or t[i-1][j];
        else
        t[i][j]=t[i-1][j];
    }
    
    return t[N][sum];
    }

    int equalPartition(int N, int arr[])
    {
        int sum=0;
        sum=accumulate(arr, arr+N, sum);
        if(sum%2!=0)
        return 0;
        else
        return isSubsetSum(arr,N,sum/2);
    }