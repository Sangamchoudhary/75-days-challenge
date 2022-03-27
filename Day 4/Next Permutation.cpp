class Solution {
public:
    void nextPermutation(vector<int>& arr){
        int n = arr.size();
        int k = -1;
        
        for(int i=n-2;i>=0;i--){
            if(arr[i] < arr[i+1]){
                k = i;
                break;
            }
        }
        
        if(k == -1){
            reverse(arr.begin(),arr.end());
        }else{
            for(int i=n-1;i>k;i--){
                if(arr[i] > arr[k]){
                    swap(arr[i],arr[k]);
                    break;
                }
            }
            reverse(arr.begin() + k + 1,arr.end());
        } 
        
    }
};