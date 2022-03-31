class Solution {
public:
    int findPairs(vector<int>& arr, int k){
        int count=0;
        int n = arr.size();
        int i=0,j=1;
        sort(arr.begin(),arr.end());
        
        while(j < n){
            if(arr[j] - arr[i] == k){
                count++;
                i++ , j++;
                while(j < n and arr[j] == arr[j-1]) j++;
            }
            else if(arr[j] - arr[i] < k){
                j++;
            }
            else{
                i++;
                if(i == j) j++;
            }
        }
        
        return count;
    }
};