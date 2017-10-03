class Solution {
public:
    bool isValid(int x, int y, int sizeX, int sizeY)
    {
        if (x < 0) return false;
        if (x >= sizeX) return false;
        if (y < 0) return false;
        if (y >= sizeY) return false;
        return true;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int direct[9][2] = {{0, 0}, {1, 0}, {-1, 0}, {1, 1}, {0, 1}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}};
        vector<vector<int>> result;
        int sizeX = M.size();
        int sizeY = M[0].size();
         for(int i = 0; i < sizeX; ++i)
         {
             vector<int> line;
             
             for(int j = 0; j < sizeY; ++j)
             {
                 int tempResult = 0;
                 int cnt = 0;
                 for(int k = 0; k < 9; ++k)
                 {
                     int newX = i + direct[k][0];
                     int newY = j + direct[k][1];
                     if(! isValid(newX, newY, sizeX, sizeY)) continue;
                     tempResult += M[newX][newY];
                     cnt++;
                     
                 }
                 
                 line.push_back(tempResult/cnt);
             }
             result.push_back(line);
         }
        return result;
    }
};


/*
189ms 32.20%
大致思路就是暴力了？
注意 vector<vector<int>> 刚刚声明的result不能直接 result[i][j]访问，
会认为是空指针。
所以每次都要先vector<int> line, 计算好的数值每次都line.push_back(), 然后
result.push_back(line).

还有一个问题，审题。这里不是每次都 /9, 比如[0][0]位置就是 /4


其他人的方法好像都是这样的暴力了
*/