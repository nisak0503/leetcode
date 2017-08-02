class Solution {
public:
    int uniquePaths(int m, int n) {
        long long res = 1;
        int minNum = min(m, n);
        for(int i = 0; i < minNum-1; ++i)
        {
            res *= (n+m-2-i);
        }
        for(int i = 0; i < minNum-1; ++i)
        {
            res /= (i+1);
        }
        return res;
    }
};

/*
3ms 2.36%
注意两点
1. 整数除以整数可能就挂了 比如 4*3/(2*1) = 4/1 * (3/2) = 4了
2. 当 m = n = 10时，res 超过了2147483647， 这里用了long long

这速度太丢人了。
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        double res = 1;
        int minNum = min(m, n);
        for(int i = 0; i < minNum-1; ++i)
        {
            res *= (n+m-2-i) *1.0/(i+1);
        }
        if(res > (int)res + 0.5) return (int)res+1;
        else return (int)res;
    }
};
/*
0ms, 42.36%
自己写了个四舍五入
这个击败百分比真是有毒，精确到多少啊。。
准备多次跑跑。。
结论：没啥变化

下面看一个DP，这不就是。。组合公式么。。嘘，不告诉那些外国人。
仍然是42.36%,好气啊。
*/

class Solution {
    int uniquePaths(int m, int n) {
        vector<vector<int> > path(m, vector<int> (n, 1));
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                path[i][j] = path[i - 1][j] + path[i][j - 1];
        return path[m - 1][n - 1];
    }
};