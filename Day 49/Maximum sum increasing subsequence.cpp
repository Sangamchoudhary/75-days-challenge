class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    int t[n];
	    t[0] = arr[0];
	    int ans = *max_element(arr,arr+n);
	    for(int i=1;i<n;i++){
	        t[i] = arr[i];
	        for(int j=0;j<i;j++){
	            if(arr[i] > arr[j]){
	                t[i] = max(t[i] , t[j] + arr[i]);
	            }
	            ans = max(ans,t[i]);
	        }
	    }
	    return ans;
	}  
};