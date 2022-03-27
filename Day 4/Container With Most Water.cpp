class Solution {
public:
    int maxArea(vector<int>& height){
        int n = height.size();
        int i = 0, j = n-1;
        int ans = 0;
        while(i < j){
            int left = height[i], right = height[j];
            
            int curr = min(left,right) * (j-i);
            
            ans = max(ans,curr);
            
            if(left < right) i++;
            else j--;
        }
        return ans;
    }
};