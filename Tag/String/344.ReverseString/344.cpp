class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
};

/*
9ms 23.78%

没什么好说的呀，学到的~

如果不用reverse的话，用交换来做, 时间不变
*/

class Solution {
public:
    string reverseString(string s) {
        int i = 0, j = s.length()-1;
        while(i < j)
        {
            swap(s[i++], s[j--]);
        }
        return s;
    }
};