class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        vector<int> ans;
        deque<int> dq;
        int i=0,j=0,n=arr.size();
        while(j < n){
            while(dq.size() and arr[dq.back()] <= arr[j]) dq.pop_back();
            dq.push_back(j);
            if(j-i+1 == k){
                ans.push_back(arr[dq.front()]);
                while(dq.size() and dq.front() <= i) dq.pop_front();
                i++;
            }
            j++;
        }
        return ans;        
    }
};