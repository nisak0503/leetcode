class Solution {
public:
    char findTheDifference(string s, string t) {
        for(char tt : t)
        {
            bool found = false;
            for(int i = 0; i < s.size(); ++i)
            {
                if(s[i] == tt)
                {
                    s.erase(s.begin() + i);
                    found = true;
                    break;
                }
            }
            if(!found) return tt;
        }
        return '\0';
    }
};

/*
6ms, 17.58%
最蠢的方法了 O(n^2)

有个很机智的方法
3ms, 60.91%
因为t每次比s多一个，所以只要把所有char转换成int再相减，多出来的那个就是要的char的INT数值了
*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        int charInt = t[0];
        for(int i = 0; i < s.size();++i)
        {
            charInt += (int) t[i+1];
            charInt -= (int) s[i];
        }
        return (char) charInt;
    }
};

