class Solution {
public:
    char isAlpha(char c)
    {
        if(c >= 'a' && c <= 'z') return c;
        if(c >= 'A' && c <= 'Z') return c = c - 'A' + 'a';
        if(c >= '0' && c <= '9') return c;
        return NULL;
    }
    bool isPalindrome(string s) {
        int head = 0, tail = s.length()-1;
        while(head <= tail)
        {
            
            while(head < s.length() && isAlpha(s[head]) == NULL) head++;
            while(tail >= 0 && isAlpha(s[tail]) == NULL) tail--;
            if(tail < 0 || head >= s.length() || tail < head) return true;

            if(head <= tail)
            {
                char h = isAlpha(s[head]);
                char t = isAlpha(s[tail]);
                if(h == NULL || t==NULL || h != t) return false;
            }
            head++;
            tail--;
                
        }
        return true;
    }
};

/*
9ms, 27.50%
注意审题，除了字母以外，数字也是可以的

*/