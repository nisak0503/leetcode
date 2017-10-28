class Solution {
public:
    string convertToTitle(int n) {
        string s = "";
        while(n)
        {
            int res = n % 26;
            if(res == 0) 
            {
                n--;
                res = 26;
            }
            char c = res + 'A' - 1;
            s = c + s;
            
            n /= 26;
        }
        return s;
    }
};

/*
0ms, 19.93% 
错了好多次
这道题不是典型的26进制！！！因为没有0这种情况
首先注意 res == 0的时候要变成 26(Z)
其次 在26的倍数时会遇到问题，比如 Z/= 26此时Z=1会继续进行while循环
    比如52的时候Z/= 26 Z=2, 但是52写成 AZ 即 1*26+26 是允许的
所以我判断了一下，如果是26的倍数，就让Z小一个


根据标答 corner case就是26的情况，所以要记得-1

0ms, 19.93%
*/
string convertToTitle(int n) {
        string ans;
        while (n) {
            ans = char ((n - 1) % 26 + 'A') + ans;
            n = (n - 1) / 26;
        }
        return ans;
    }

