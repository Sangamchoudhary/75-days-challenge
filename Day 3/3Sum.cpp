class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<=n-3;i++){
            int j = i+1,k=n-1;
            
            while(j < k){
                int first = arr[i] , second = arr[j] , third = arr[k];
                int sum = first + second + third;
                
                if(i != j and j != k and k != i and sum == 0){
                    ans.push_back({first,second,third});  
                    int last_left = arr[j], last_right = arr[k];
                    
                    while (j < k && arr[j] == last_left) ++j;
                    while (j < k && arr[k] == last_right) --k;
                }
                else if(sum > 0) k--; 
                else j++;
            }
            
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};