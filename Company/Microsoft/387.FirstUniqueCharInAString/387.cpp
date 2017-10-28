class Solution {
public:
    int firstUniqChar(string s) {
        if(s.length() == 0) return -1;
        if(s.length() == 1) return 0;
        unordered_set<int> copied;
        
        for(int i = 0; i < s.length()-1; ++i)
        {
            if(copied.find(i) != copied.end()) continue; //already has copy
            bool copy = false;
            for(int j = i+1; j < s.length(); ++j)
            {
                if(s[i] == s[j])
                {
                    copied.insert(i);
                    copied.insert(j);
                    copy = true;
                }
            }
            if(!copy) return i;
        }
        if(copied.find(s.length()-1) != copied.end()) return -1;
        else return s.length()-1;
    }
    
};

/*
275ms, 0.21%
超级无敌巨慢
length() == 0, 1是因为 length() 的返回值类型是 size_t, 是无符号的，-1之后就变得非常大
unordered_set的作用是标记是否被判重过
copy的作用是判断当前字符是否重复了
注意，i只完成了 s.length()-1个，最后一个还是要判断一下，所以有第23行的if


标答的办法，直接算个数啊，摔！
86ms, 17.38%
*/
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for(char c : s)
        {
            m[c]++;
        }
        for(int i = 0; i < s.length(); ++i)
        {
            if(m[s[i]] == 1) return i;
        }
        return -1;
    }
    
};

