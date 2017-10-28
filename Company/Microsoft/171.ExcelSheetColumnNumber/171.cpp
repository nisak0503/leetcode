class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        int size = s.length();
        for(int i = 0; i < s.length(); ++i)
        {
            result += (s[i] - 'A' + 1) * pow(26, size-i-1);
        }
        return result;
    }
};

/*
3ms 48.89%
easy enough
*/