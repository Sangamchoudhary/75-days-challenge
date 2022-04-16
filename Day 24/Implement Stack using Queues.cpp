class MyStack {
private:
    queue<int> q;
public:
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int sz = q.size() - 1;
        while(sz--){
            int ele = q.front(); q.pop();
            q.push(ele);
        }
        int ans = q.front(); q.pop();
        return ans;
    }
    
    int top() {
        int sz = q.size() - 1;
        while(sz--){
            int ele = q.front(); q.pop();
            q.push(ele);
        }
        int ans = q.front(); q.pop();
        q.push(ans);
        return ans;        
    }
    
    bool empty() {
        return q.empty();
    }
};