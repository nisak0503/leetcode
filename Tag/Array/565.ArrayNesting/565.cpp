class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<int> flags;
        int max = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            flags.push_back(-1);
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            if(flags[i] > 0) continue;
            int begin = i;
            int cnt = 0;
            while(flags[begin] < 0)
            {
                flags[begin] = i;
                cnt++;
                begin = nums[begin];
            }
            if(max < cnt)
            {
                max = cnt;
            }
        }
        return max;
    }
};

/*
58ms 15.62%
一道非常简单的题目，一次过。
置换问题，不多说。O(n)的时间复杂度，O(n)的空间复杂度

但是还有一种O(1)空间复杂度的方法。
说了都是1-20000的数，所以可以把访问过的修改为MAX_VALUE in JAVA
我的想法是，可以改成 负值，比较讨巧吧。

*/