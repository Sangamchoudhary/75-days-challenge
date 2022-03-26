class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int num1 = nums[0];
        int c1 = 0;
        
        for(auto it : nums){
            if(it == num1){
                c1++;
            }else{
                c1--;
                if(c1 == 0){
                    num1 = it;
                    c1 = 1;
                }
            }
        }       
        
        return num1;
        
    }
};