class Solution {
public:
    int addDigits(int num) {
        while(num >= 10)
        {
            int sum = 0;
            while(num >= 10)
            {
                sum += num % 10;
                num /= 10;
            }
            sum += num;
            num = sum;
        }
        return num;
    }
};

/*
最暴力的方法 6ms 7.78%
这里注意sum的位置

然而有个followup 如何不用loop O(1)做出来？

下面是自己推出来的方法 3ms, 48.27%
想法是找规律

num < 10的时候 0 1 2 3 4 5 6 7 8 9
num >= 10的时候 1 2 3 4 5 6 7 8 9 1
                2 3 4 5 6 7 8 9 1 2
                ....
        9x 的时候9 1 2 3 4 5 6 7 8 9
        100的时候1 2 3 4 5 6 7 8 9 1
        11x的时候2 3 4 5 6 7 8 9 1 2
        ...

所以每次都在循环，n = （num / 10）% 9 看第一位是什么
如果为0就认为是9
然后 num % 10 就是从n开始数几位， n, n+1, n+2, ...n + num%10
但是如果到9之后就要从1开始
*/
class Solution {
public:
    int addDigits(int num) {
        if(num < 10) return num;
        int n = (num / 10) % 9;
        if(n == 0) n = 9;
        int m = num % 10 + n;
        if(m > 9) m -= 9;
        return m;
    }
};


/*
这实际上是digit root问题
https://en.wikipedia.org/wiki/Digital_root#Congruence_formula

For base b (decimal case b = 10), the digit root of an integer is:

dr(n) = 0 if n == 0
dr(n) = (b-1) if n != 0 and n % (b-1) == 0
dr(n) = n mod (b-1) if n % (b-1) != 0
or

dr(n) = 1 + (n - 1) % 9
时间还是 3ms, 48.27%
*/
class Solution {
public:
    int addDigits(int num) {
        return 1+(num-1)%9;
    }
};
