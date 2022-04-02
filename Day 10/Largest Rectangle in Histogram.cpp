class Solution {
public:
    // whenever we encounter with a smaller element than stack's top, that itself is the right 
    // boundary for the stack's top element
    // and left boundary will be the next stack's top element 
    
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        int area=0;
        for(int i=0;i<n;i++){
            while(!st.empty() and arr[i] <= arr[st.top()]){   
                int height = arr[st.top()];
                st.pop();
                int width;
                if(st.empty()) width = i;
                else width = i - st.top() - 1;
                    
                int currArea = height * width;
                area = max(area , currArea);
            }
            st.push(i);
        }
        
        while(!st.empty()){
                int height = arr[st.top()];
                st.pop();
                int width;
                if(st.empty()) width = n;
                else width = n - st.top() - 1;
                    
                int currArea = height * width;
                area = max(area , currArea);           
        }
        
        return area;
    }
};