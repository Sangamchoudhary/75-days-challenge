class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i = n-1;
        int carry = 1;
        while(i >= 0){
            int add = digits[i] + carry;
            int num = add % 10;
            add /= 10;
            carry = add;
            digits[i] = num;
            i--;
        }
        if(carry){
            digits.insert(digits.begin(),carry);
        }
        return digits;
    }
};