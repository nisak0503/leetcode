class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";
        for(char c : s)
        {
            if(c == ' ')
            {
                ans += temp + " ";
                temp = "";
                continue;
            }
            temp = c + temp;
        }
        ans += temp;
        return ans;
    }
};

/*
49ms 5.34%

才知道C++的string是最惨的

下面这个方法只在s上做文章，把里面的词都反转了。
其中reverse是左闭右开的反转
26ms, 32.80%
*/

class Solution {
public:
    string reverseWords(string s) {
        for(int i = 0; i < s.length(); ++i)
        {
            if(s[i] != ' ')
            {
                int j = i;
                for(;j < s.length() && s[j] != ' '; ++j)
                { 
                }
                reverse(s.begin() + i, s.begin() + j);
                i = j - 1;
            }
        }
        return s;
    }
};
