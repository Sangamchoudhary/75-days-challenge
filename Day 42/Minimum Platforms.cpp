class Solution{
    public:
    int findPlatform(int arv[], int dep[], int n){
    	sort(arv,arv+n); sort(dep,dep+n);
    	int i=0, j=0;
    	int total_platforms = 0, max_trains = 0;;
    	while(i < n and j < n){
    	    if(arv[i] <= dep[j]){
    	        max_trains++;
    	        i++;
    	    }else{
    	        max_trains--;
    	        j++;
    	    }
    	    total_platforms = max(total_platforms,max_trains);
    	}
    	return total_platforms;
    }
};