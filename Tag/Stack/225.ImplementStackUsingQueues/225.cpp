class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    queue<int> bufq;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(q.size() > 1)
        {
            bufq.push(q.front());
            q.pop();
        }
        int ans = q.front();
        q.pop();
        while(!bufq.empty())
        {
            q.push(bufq.front());
            bufq.pop();
        }
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        while(q.size() > 1)
        {
            bufq.push(q.front());
            q.pop();
        }
        int ans = q.front();
        bufq.push(ans);
        q.pop();
        while(!bufq.empty())
        {
            q.push(bufq.front());
            bufq.pop();
        }
        return ans;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */


/*
题目都暗示是多个队列了。。。easy
0ms, 44.68%
push O(1)
pop O(n)

然而只用一个queue也是可以的

stack  1 2 <- 3
queue 2 1 <- 3
queue 2 1 3
queue 1 3 2
queue 3 2 1
每次操作循环一次 O(n)
空间复杂度 O(1)



*/