class Solution {
public:
    bool check(string word)
    {
        
        if (word == "") return true;
        int row  = 0;
        for(char ch : word)
        {
            int r = 0;
            if(ch <= 90)
            {
                ch += 32;
            }
            switch (ch)
            {
                case 'q':
                case 'w':
                case 'e':
                case 'r':
                case 't':
                case 'y':
                case 'u':
                case 'i':
                case 'o':
                case 'p': r = 1; break;
                    
                case 'a':
                case 's':
                case 'd':
                case 'f':
                case 'g':
                case 'h':
                case 'j':
                case 'k':
                case 'l': r = 2; break;
                
                case 'z':
                case 'x':
                case 'c':
                case 'v':
                case 'b':
                case 'n':
                case 'm': r = 3; break;
                default:;
            }
            if(row == 0)
            {
                row = r;
            }
            if(row != r)
            {
                return false;
            }
        }
        return true;
    }
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        for(int i = 0; i < words.size(); ++i)
        {
            if(check(words[i]))
            {
                res.push_back(words[i]);
            }
        }
        return res;
    }
};

/*
3ms, 1.31%
慢出了新境界了。

作为字符串来查找的话。。

0ms, 52.22% 感觉不错
看起来需要整理一下string的方法了？

*/

class Solution {
private:
    string s1 = "qwertyuiopQWERTYUIOP";
    string s2 = "asdfghjklASDFGHJKL";
    string s3 = "zxcvbnmZXCVBNM";
    
public:
    bool check(string word)
    {
        
        if (word == "") return true;
        int row  = 0;
        for(char ch : word)
        {
            int r = 0;
            if (s1.find(ch) != -1)
            {
                r = 1;
            }
            
            if (s2.find(ch) != -1)
            {
                r = 2;    
            }
            if (s3.find(ch) != -1)
            {
                r = 3;
            }
            if(row == 0)
            {
                row = r;
            }
            if(row != r)
            {
                return false;
            }
        }
        return true;
    }
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        for(int i = 0; i < words.size(); ++i)
        {
            if(check(words[i]))
            {
                res.push_back(words[i]);
            }
        }
        return res;
    }
};