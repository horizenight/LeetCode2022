class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    MyQueue() {


    }
    
    void push(int x) {
        // first move s1 -> s2 
        // then inset in s1 
        // then s2 -> s1

        while(!s1.empty()){
            int top = s1.top();s1.pop();
            s2.push(top);
        }
        s1.push(x);
         while(!s2.empty()){
            int top = s2.top();s2.pop();
            s1.push(top);
        }
    }
    
    int pop() {
        int top = s1.top();s1.pop();
        return top;
    }
    
    int peek() {
         int top = s1.top();
        return top;
    }
    
    bool empty() {
        if(s1.empty()) return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */