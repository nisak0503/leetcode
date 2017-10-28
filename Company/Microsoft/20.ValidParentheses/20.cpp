class Solution {
public:
    bool isValid(string s) {
        char stack[10000];
        int ptr = -1;
        for(char c : s)
        {
            switch(c)
            {
                case '(': stack[++ptr] = c; break;
                case ')': if(ptr < 0 || stack[ptr] != '(') return false; else ptr--; break;
                case '[': stack[++ptr] = c; break;
                case ']': if(ptr < 0 || stack[ptr] != '[') return false; else ptr--; break;
                case '{': stack[++ptr] = c; break;
                case '}': if(ptr < 0 || stack[ptr] != '{') return false; else ptr--; break;
            }
        }
        if (ptr == -1) return true;
        return false;
    }
};

/*
3ms, 9.51%
速度也是慢的可以QAQ

提交了几次的错误
第一个，这是个栈，不能简单用3个变量++ --来做，顺序很重要
第二个，ptr < 0的情况在case里逻辑是||

可以直接用stack<char> 来做, 时间还是3ms好嘛！根本没有标答说的2ms
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
      
        for(char c : s)
        {
            switch(c)
            {
                case '(':
                case '[':
                case '{': paren.push(c); break;
                case ')': if(paren.empty() || paren.top() != '(') return false; else paren.pop(); break;
                
                case ']': if(paren.empty() || paren.top() != '[') return false; else paren.pop(); break;
                
                case '}': if(paren.empty() || paren.top() != '{') return false; else paren.pop(); break;
            }
        }
        if(paren.empty()) return true;
        return false;
    }
};