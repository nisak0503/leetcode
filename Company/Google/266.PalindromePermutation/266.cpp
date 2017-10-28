class Solution {
public:
    bool canPermutePalindrome(string s) {
        int num[128] = {0};
        for(char c : s)
        {
            num[c]++;   
        }
        bool odd = false;
        for(int n = 0; n < 128; ++n)
        {
            if(num[n] % 2 == 1)
            {
                if(!odd) 
                {
                    odd = true;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};

/*
因为是字符串，所以可能用到0-127所有128个字符
暴力一下，3ms, 1.27% 太弱了

换成unordered_map, hash一下
0ms, 28.62%
*/
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> num;
        for(char c : s)
        {
            num[c]++;   
        }
        bool odd = false;
        for(unordered_map<char, int>::iterator it = num.begin(); it != num.end(); ++it)
        {
            
            if(it->second % 2 == 1)
            {
                if(!odd) 
                {
                    odd = true;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};