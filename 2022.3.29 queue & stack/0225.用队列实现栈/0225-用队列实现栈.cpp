class MyStack {
public:
    queue<int> que1;
    queue<int> que2;
    MyStack() {

    }
    
    void push(int x) {
        que1.push(x);
    }
    
    int pop() {
        int size = que1.size();
        size--;
        while(size) {
            que2.push(que1.front());
            que1.pop();
            size--;
        }
        int result = que1.front();
        que1.pop();
        que1 = que2;
        while (!que2.empty()) {
            que2.pop();
        }
        return result;
    }
    
    int top() {
        return que1.back();
    }
    
    bool empty() {
        return que1.empty();
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