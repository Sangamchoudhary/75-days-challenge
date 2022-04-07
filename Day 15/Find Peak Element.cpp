class Solution {
public:
    int findPeakElement(vector<int>& arr){
       int n = arr.size();
       int i=0,j=n-1;
       int mid;
       if(n == 1) return 0;
       while(i <= j){
           mid = (i+j)/2;
           if(mid == 0){
               if(arr[mid] > arr[mid+1]) return mid;
               else i = mid+1;
           }else if(mid == n-1){
               if(arr[mid] < arr[mid-1]) return mid-1;
               else j = mid-1;
           }else{
               if(arr[mid] < arr[mid+1]){
                   i = mid+1;
               }else if(arr[mid] > arr[mid+1] and arr[mid] > arr[mid-1]){
                   return mid;
               }else{
                   j = mid-1;
               }
           }
       }
       
       return mid;        
    }
};