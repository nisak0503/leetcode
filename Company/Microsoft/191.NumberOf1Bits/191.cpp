class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n)
        {
            if (n & 1 == 1) ans++;
            n = n >> 1;
        }
        return ans;
    }
};

/*
3ms, 25.62%
好像没难度。。。
慢了

还有一种想法 还是3ms, 25.62%
比如 110100   n
和   110011   n-1
&一下110000 就会少一个最小的1
这样可以计算1的个数

*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n)
        {
           ans++;
           n = n & (n-1);
        }
        return ans;
    }
};