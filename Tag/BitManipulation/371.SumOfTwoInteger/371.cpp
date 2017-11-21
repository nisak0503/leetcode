class Solution {
public:
    int getSum(int a, int b) {
        int sum = a;
        while(b != 0)
        {
            sum = a ^ b;
            b = (a & b) << 1;
            a = sum;
        }
        return sum;
    }
};

/*
0ms, 23.59%

Failed


对每一位进行 位与 则 01 & 01 获得 01 左移一位 进位 10
还需要加 0
01 ^ 01 = 00

每一位 的计算可以同时做呀，因为不会影响其他位
*/