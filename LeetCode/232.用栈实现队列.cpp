/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {

    }
    
    void push(int x) {
        while(!st2.empty()){
            int a = st2.top();
            st2.pop();
            st1.push(a);
        }
        st1.push(x);
    }
    
    int pop() {
        while(!st1.empty()){
            int a = st1.top();
            st1.pop();
            st2.push(a);
        }
        int res = st2.top();
        st2.pop();
        return res;
    }
    
    int peek() {
        while(!st1.empty()){
            int a = st1.top();
            st1.pop();
            st2.push(a);
        }
        int res = st2.top();
        return res;
    }
    
    bool empty() {
        return st1.size() == 0 && st2.size() == 0;
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
// @lc code=end

