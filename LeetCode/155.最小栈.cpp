/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
private:
    stack<int> st1;
    stack<int> st2;
public:
    MinStack() {
    }
    
    void push(int val) {
        st1.push(val);
        if(st2.empty() || val < st2.top()){
            st2.push(val);
        } else{
            st2.push(st2.top());
        }
    }
    
    void pop() {
        st1.pop();
        st2.pop();
    }   
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

// 7 5 4 6 7 8 9 6 5
// 7 5 4 4 4 4 4 4 4