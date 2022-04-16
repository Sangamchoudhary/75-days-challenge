class MyQueue {
private:    
    stack<int> st1,st2;
public:
    void push(int x) {
        st1.push(x); 
    }
    
    int pop() {
        int ans, sz = st1.size() - 1;
        while(sz--){
            st2.push(st1.top()); st1.pop();
        }
        ans = st1.top(); st1.pop();
        while(st2.size()){
            st1.push(st2.top()); st2.pop();
        }
        return ans;
    }
    
    int peek() {
        int ans, sz = st1.size() - 1;
        while(sz--){
            st2.push(st1.top()); st1.pop();
        }
        ans = st1.top(); st1.pop();
        st2.push(ans);
        while(st2.size()){
            st1.push(st2.top()); st2.pop();
        }
        return ans;        
    }
    
    bool empty() {
        return st1.empty();
    }
};