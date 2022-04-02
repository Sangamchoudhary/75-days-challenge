class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        
        int n = arr.size();
        
        //working for all -ve and 0
        for(int i=0;i<n;i++){
            if(arr[i] <= 0){
                arr[i] = n+1;
            } 
        }
        
        // working for all +ve numbers
        for(int i=0;i<n;i++){
            
            int ele = abs(arr[i]);
            int idx = ele - 1;
            
            if(idx < n and arr[idx] > 0){
                arr[idx] *= -1;
            }
            
        }
        
        //final work for numbers who is missing
        for(int i=0;i<n;i++){
            if(arr[i] > 0)
                return i+1;
        }
        
        //if no number in found inside the array then our last option
        return n+1;
    }
};