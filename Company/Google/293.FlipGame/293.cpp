class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        for(int i = 1; i < s.size(); ++i)
        {
            if(s[i] == s[i-1] && s[i] == '+')
            {
                string ss = s;
                ss[i] = '-';
                ss[i-1] = '-'; 
                res.push_back(ss);
            }
        }
        return res;
    }
};

/*
第一次提交题目审题审错了，--是不能翻牌的
3ms, 0.28%
这个效率太低了

凑一下还是3ms, 0.28%
*/

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        int len = s.size();
        for(int i = 1; i < len; ++i)
        {
            if(s[i] == s[i-1] && s[i] == '+')
            {
                res.push_back(s.substr(0, i-1) + "--" + s.substr(i+1, len-i));
            }
        }
        return res;
    }
};