class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    int minNum;
    MinStack() {
        minNum = INT_MAX;
    }
    
    void push(int x) {
        s.push(x);
        minNum = min(minNum, x);
    }
    
    void pop() {
        int bye = s.top();
        if(bye == minNum)
        {
            minNum = INT_MAX;
            stack<int> buf = s;
            buf.pop();
            while(!buf.empty())
            {
                minNum = min(minNum, buf.top());
                buf.pop();
            }
        }
        s.pop();
    }
    
    int top() {
        return s.top();   
    }
    
    int getMin() {
        return minNum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */


/*
出了个bug， pop时掉了21行这句Pop
32ms, 25.73%

我这个方法 pop时O(n)了

讨论中有人用两个stack做的。
可以让所有操作都O(1)
这里注意 x <= getMin() 是一定要等号的，因为到时候删了一个，最小的还存在。
*/

class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= getMin())  s2.push(x);       
    }
    void pop() {
        if (s1.top() == getMin())  s2.pop();
        s1.pop();
    }
    int top() {
        return s1.top();
    }
    int getMin() {
        return s2.top();
    }
};

/*
自己也写了一遍
29ms, 34.54%
*/

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> minS;
    MinStack() {
    }
    
    void push(int x) {
        s.push(x);
        if(minS.empty() || getMin() >= x) minS.push(x);
    }
    
    void pop() {
        if(s.top() == minS.top())
        {
            minS.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();   
    }
    
    int getMin() {
        return minS.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
