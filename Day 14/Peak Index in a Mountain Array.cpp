class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = n-1;
        
        while(i < j){
            int mid = (i+j)/2;
            if(arr[mid] > arr[mid+1]){
                j = mid;
            }else{
                i = mid + 1;
            } 
        }
        
        return i;
    }
};