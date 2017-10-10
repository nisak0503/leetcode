class Solution {
public:
    int hammingDistance(int x, int y) {
        vector<int> onex;
        vector<int> oney;
        while(x > 0)
        {
            onex.push_back(x % 2);
            x /= 2;
        }
        while(y > 0)
        {
            oney.push_back(y % 2);
            y /= 2;
        }
        int ans = 0;
        for(int i = 0; i < max(onex.size(), oney.size()); ++i)
        {
            int xx = i < onex.size() ? onex[i] : 0;
            int yy = i < oney.size() ? oney[i] : 0;
            if(xx != yy) ans++;
        }
        return ans;
    }
};

/*
25.87%

最好的方法当然是bit manipulation啦。。
不记得了，复习一下。

http://blog.csdn.net/jason314/article/details/5719933

~  位求反   ~expr
<< 左移     expr1 << expr2
>> 右移     expr1 >> expr2
&  位与     expr1 & expr2
^  位异或   expr1 ^ expr2
|  位或     expr1 | expr2

x = 3 (00000000 00000011)
y = 5 (00000000 00000101)

无符号 (unsigned short) ~x
~x = (11111111 11111100) = 2^16-4 = 65532

有符号 （补码）
反码，原码除符号位外各位数求反
补码，反码+1
~x = (11111111 11111100) - 补码
   = (11111111 11111011) - 反码
   = (00000000 00000100) -原码
   = 4
x & y = (00000000 00000001) = 1
x ^ y = (00000000 00000110) = 6
x | y = (00000000 00000111) = 7
x << 1 = (00000000 00000110) = 6
y >> 1 = (00000000 00000010) = 2

解读一下这道题，
 n = x ^ y 表示有这么多不一样的位数 eg. (0001001011000110)
 接下来计算里面1的个数
 只要n > 0说明里面还有1
 n与(n-1)的值，就是把最后一位，标记为0
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = 0, n = x ^ y;
        while (n) {
            ++dist;
            n &= n - 1;
        }
        return dist;
    }
};


/*
我写的，还是25.87%啊！！摔！
*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int ans = 0;
        while(n > 0)
        {
            ans++;
            n &= (n-1);
        }
        return ans;
    }
};
