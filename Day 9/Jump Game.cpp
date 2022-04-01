class Solution {
public:
    bool solve(int i,int msf,vector<int> &nums){
        if(i == nums.size()){
            if(msf >= nums.size()-1) return true;
            return false;
        }else if(i > msf) return false;
        
        msf = max(msf,i + nums[i]);
        int res = solve(i+1,msf,nums);
        return res;
    }
    bool canJump(vector<int>& nums){
        return solve(0,0,nums);
    }
};