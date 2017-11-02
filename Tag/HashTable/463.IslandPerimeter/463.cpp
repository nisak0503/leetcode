class Solution {
private:
    vector<vector<int>> direct = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    vector<vector<bool>> visit;
    int cal(vector<vector<int>>&grid, int x, int y)
    {
        int sum = 0, result = 0;
        visit[x][y] = true;
        for(int i = 0; i < direct.size(); ++i)
        {
            int newx = x + direct[i][0];
            if(newx >= grid.size() || newx < 0) continue;
            int newy = y + direct[i][1];
            if(newy >= grid[x].size() || newy < 0) continue;
            if(grid[newx][newy])
            {
                sum++;
                if(!visit[newx][newy])
                {
                    result += cal(grid, newx, newy);    
                }
            }
        }
        result += (4-sum);
        return result;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); ++i)
        {
            vector<bool> temp;
            for(int j = 0; j < grid[i].size(); ++j)
            {
                temp.push_back(false);
            }
            visit.push_back(temp);
        }
        for(int x = 0; x < grid.size(); ++x)
        {
            for(int y = 0; y < grid[x].size(); ++y)
            {
                if(grid[x][y])
                {
                    return cal(grid, x, y);
                }
            }
        }
    }
};


/*
我好像做成了DFS？
152ms 61.62%

好了我心痛了
明明可以直接数学计算的。。
有多少1就有多少个4倍的边数
但是相邻只要有接壤就减去一次，（因为重复算了）
这里从左往右，从上往下，所以只要看之前上面和左边的就好
*/
int islandPerimeter(vector<vector<int>>& grid) {
        int count=0, repeat=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0; j<grid[i].size();j++)
                {
                    if(grid[i][j]==1)
                    {
                        count ++;
                        if(i!=0 && grid[i-1][j] == 1) repeat++;
                        if(j!=0 && grid[i][j-1] == 1) repeat++;
                    }
                }
        }
        return 4*count-repeat*2;
    }