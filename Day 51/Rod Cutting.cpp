class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> rodArray(n);
        for(int i=0;i<n;i++)
        {
            rodArray[i]=i+1;
        }
        vector<vector<int>> t(n+1,vector<int>(rodArray.size()+1,-1));
        return helper(price,rodArray,n,rodArray.size(),t);
    }
    int helper(int price[],vector<int>& rodArray,int n,int length, vector<vector<int>>&t)
    {
        if(n==0 || length==0)
        {
            return 0;
        }
        if(t[n][length]!=-1)
        {
            return t[n][length];        
        }
        
        if(rodArray[n-1]<=length)
        {
           t[n][length]= max(price[n-1]+helper(price,rodArray,n,length-rodArray[n-1],t),
           helper(price,rodArray,n-1,length,t));
           return t[n][length];
        }
        else
        {
            t[n][length]= helper(price,rodArray,n-1,length,t);
            return t[n][length];
        }
    }
};