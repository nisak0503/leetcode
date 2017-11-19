class Solution {
public:
    int findMaxLength(string a, string b){
        int maxLength = -1;
        for(int i = 0; i < a.size(); ++i)
        {
            string s = "";
            for(int j = i; j < a.size(); ++j)
            {
                s+= a[j];
                if(b.find(s) != string::npos)
                {
                    continue;    
                }
                else
                {
                    maxLength = max(maxLength, j-i+1);
                }
            }
        }
        return maxLength;
    }
    int findLUSlength(string a, string b) {
        int x = findMaxLength(a, b);
        int y = findMaxLength(b, a);
        return x > y ? x : y;
    }
};

/*
有点没时间看，要复习174A的考试
最愚蠢的方法了
6ms, 0.72%
烂哦。

仔细思考一下：无非两种情况，两者相等 -1
两者不等，取最长的呀
0ms, 72.98%
*/

class Solution {
public:
    
    int findLUSlength(string a, string b) {
        if(a == b) return -1;
        return max(a.size(), b.size());
    }
};