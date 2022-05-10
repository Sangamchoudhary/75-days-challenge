class Solution {
public:
    void solve(int i,vector<int> &arr,vector<int> v,vector<vector<int>> &ans){
        if(i >= arr.size()){
            ans.push_back(v);
            return;
        }
        v.push_back(arr[i]);
        solve(i+1,arr,v,ans);
        v.pop_back();
        solve(i+1,arr,v,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(0,nums,v,ans);
        return ans;
    }
};