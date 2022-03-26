class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        int sum = 0;
        for(auto &it : arr){
            sum += it;
            it = sum;
        }
        
        int n = arr.size();
        for(int i=0;i<n;i++){
            int l_sum = (i-1 >= 0) ? arr[i-1] : 0;
            int r_sum = (i+1 < n) ? arr[n-1] - arr[i] : 0;
            
            if(l_sum == r_sum) return i;
        }
        
        return -1;
    }
};