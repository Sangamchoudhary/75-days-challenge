class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        ans.push_back({arr[0][0],arr[0][1]});
        
        int n = arr.size();
        for(int i=1;i<n;i++){
            if(ans.back()[1] < arr[i][0]){
                ans.push_back({arr[i][0],arr[i][1]});
            }else{
                ans.back()[1] = max(ans.back()[1],arr[i][1]);
            }
        }
        
        return ans;
    }
};