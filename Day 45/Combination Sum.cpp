class Solution {
public:
    void solve(int i,vector<int> &arr,int target,vector<int> &v,vector<vector<int>> & res){
        if(target == 0){ 
            res.push_back(v); 
            return; 
        }
        if(i == arr.size() or target < 0) return;
        
        v.push_back(arr[i]);
        solve(i,arr,target-arr[i],v,res);
        v.pop_back();
        solve(i+1,arr,target,v,res);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> res;
        vector<int> v;
        solve(0,arr,target,v,res);
        return res;
    }
};