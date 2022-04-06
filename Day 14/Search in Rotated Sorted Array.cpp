class Solution {
public:
    int findPeak(vector<int> &arr,int n){
       int i=0,j=n-1;
       int mid;
       if(n == 1) return 0;
       while(i <= j){
           mid = (i+j)/2;
           if(mid == 0){
               if(arr[mid] > arr[mid+1]) return mid;
               else return mid+1;
           }
           else if(arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1]){
               return mid;
           }
           else if(arr[mid] >= arr[i]){
               if(i == mid) i++;
               else i = mid;
           }
           else{
               j = mid-1;
           }
       }
       return -1; 
    }
        
    int binarySearch(vector<int> &nums,int target,int st,int en){
        while(st<=en){
            int mid=(st+en)/2;
            if(nums[mid]==target)
                return mid;
            else if(target>nums[mid])
                st=mid+1;
            else
                en=mid-1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target){
        int n = nums.size();
        
        // It means our array is not rotated so simply search target in it
        if(nums[0] < nums[n-1]){
            return binarySearch(nums,target,0,n-1);
        } 
        
        // Serach which index is at peak
        int idx = findPeak(nums,n);
        // Now divide the search area in 2 part before pivot and after pivot
        return binarySearch(nums,target,idx+1,nums.size()-1) + binarySearch(nums,target,0,idx) + 1;
    }
};