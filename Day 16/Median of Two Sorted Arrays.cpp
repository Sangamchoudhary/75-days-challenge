class Solution {
public:
    double findMedianSortedArrays(vector<int>& a1, vector<int>& a2) {
        
        int m = a1.size();
        int n = a2.size();
        
        if(m > n) return findMedianSortedArrays(a2,a1);
        
        int med = (m + n + 1) / 2;
        
        int low = 0 , high = m;
        
        while(low <= high){
            
            int cut1 = (low + high) / 2;
            int cut2 = med - cut1;
            
            int left1 = cut1 == 0 ? INT_MIN : a1[cut1 - 1];
            int left2 = cut2 == 0 ? INT_MIN : a2[cut2 - 1];
            
            int right1 = cut1 == m ? INT_MAX : a1[cut1];
            int right2 = cut2 == n ? INT_MAX : a2[cut2];
            
            if(left1 <= right2 and left2 <= right1){
                if((m + n) % 2){
                    return max(left1,left2);
                }
                else{
                    double ans = (max(left1,left2) + min(right1,right2)) / 2.0;
                    return ans;
                }
            }
            else if(left1 > right2){
                high = cut1 - 1;
            }
            else{
                low = cut1 + 1;
            }
        }
        return 0.0;
    }
};