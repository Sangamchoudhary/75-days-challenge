class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
        
        int prev = 0;
        for(auto &it : arr) it += prev, prev = it;
        
        int i = k-1, j = n;
        int ans = 0;
        
        while(j >= n-k){
            int curr_front_score = i >= 0 ? arr[i] : 0;
            
            int curr_back_score = j < n ? (arr[n-1] - (j-1 >=0 ? arr[j-1] : 0)) : 0;
            
            int total_score = curr_front_score + curr_back_score;
            
            ans = max(ans,total_score);
            
            i--; j--;
        }
        
        return ans;
    }
};