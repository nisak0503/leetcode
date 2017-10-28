class Solution {
public:
    int countPrimes(int n) {
        bool flag[2000000] = {false};
        if(n <= 2) return 0;
        int res = 1;
        for(int i = 3; i < n; i+=2)
        {
            if(!flag[i])
            {
                res++;
                if(i <= sqrt(n))
                {
                    for(int j = i*i; j < n; j+=i)
                    {
                        flag[j] = true;
                    }
                }
            }
        }
        return res;
    }
};

/*
这道题用我以前想的方法会TLE


答案做的方法是，从奇数开始算，如果是prime就 从Prime*prime 开始每个Prime都标记一下，为合数
prime * prime是因为，前面的prime*(prime-1)都在prime-1时被计算过啦

22ms, 86.14%
*/