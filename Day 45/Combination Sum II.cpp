class Solution {
public:
    void solve(int i,vector<int> &arr,int target,vector<int> temp,vector<vector<int>> &ans){
        if(!target){
            ans.push_back(temp);
            return;
        } 
        if(i >= arr.size()) return;
        if(arr[i] <= target){
            temp.push_back(arr[i]);
            solve(i+1,arr,target-arr[i],temp,ans);   
            temp.pop_back();
        }
        while(i+1 < arr.size() and arr[i] == arr[i+1]) i++;
        solve(i+1,arr,target,temp,ans);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(arr.begin(),arr.end());
        solve(0,arr,target,temp,ans);
        return ans;
    }
};