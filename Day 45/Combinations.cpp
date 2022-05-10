class Solution {
private:
    void solve(int num,int n,int k,vector<int> &v,vector<vector<int>> &ans){
        if(k == 0){
            ans.push_back(v);
            return;
        }
        if(k < 0 or num > n) return;
        v.push_back(num);
        solve(num+1,n,k-1,v,ans);
        v.pop_back();
        solve(num+1,n,k,v,ans);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(1,n,k,v,ans);
        return ans;
    }
};