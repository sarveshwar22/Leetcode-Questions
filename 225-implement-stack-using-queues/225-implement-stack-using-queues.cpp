class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int val;
        while(!q1.empty())
        {   val=q1.front();
            q1.pop();
         if(!q1.empty())
            q2.push(val);
            
        }
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return val;
        
    }
    
    int top() {
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        int val;
        while(!q2.empty())
        {
            val=q2.front();
            q1.push(q2.front());
            q2.pop();
        }
        return val;
        
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */