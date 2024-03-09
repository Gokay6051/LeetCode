class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
    int topElement;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        topElement = x;
    }
    
    int pop() {
        while(q1.size() > 1){
            topElement = q1.front();
            q2.push(topElement);
            q1.pop();
        }
        int result = q1.front();
        q1.pop();
        swap(q1,q2);
        return result;
    }
    
    int top() {
        return topElement;
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
