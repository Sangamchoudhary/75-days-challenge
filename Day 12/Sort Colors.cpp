class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int i = 0,j=n-1;
        
        int k = 0;
        while(k <= j){
            if(arr[k] == 0){
                swap(arr[i++],arr[k++]);
            }else if(arr[k] == 2){
                swap(arr[j--],arr[k]);
            }else{
                k++;
            }
        }
        
    }
};