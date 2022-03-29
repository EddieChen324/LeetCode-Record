class MyQueue {
public:
    stack<int>stIn;
    stack<int>stOut;
    MyQueue() {

    }
    
    void push(int x) {
        stIn.push(x);
    }
    
    int pop() {
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        //Ҫȡ��ֵ���ǳ�ջ��ջ��Ԫ��
        int result = stOut.top();
        //������ջ��Ԫ��
        stOut.pop();
        return result;
    }
    
    int peek() {
        int res = this->pop();
        stOut.push(res);  //��Ϊpop����������Ԫ��res����������ӻ�ȥ
        return res;
    }
    
    bool empty() {
            return stIn.empty() && stOut.empty();
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