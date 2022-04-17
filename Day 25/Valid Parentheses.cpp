class Solution {
public:
    bool isValid(string s){
        stack<char> st;
        for(auto it : s){
            if(it == '(') st.push(')');
            
            else if(it == '{') st.push('}');
            
            else if(it == '[') st.push(']');
            
            else if(st.size() and it == st.top()) st.pop();
            
            else return false;
        }
        
        return st.empty();
    }
};