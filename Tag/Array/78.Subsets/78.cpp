#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("78.in");


class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        
        vector<int> temp;
        backTrack(res, temp, nums, 0);
        
        return res;
    }
    
    void backTrack(vector<vector<int> >& res, vector<int>& temp, vector<int> nums, int start)
    {
        res.push_back(temp);
        int size = nums.size();
        //cout << "start = "<< start<<endl;
        for(int i = start; i < size; ++i)
        {
            temp.push_back(nums[i]);
            
    
            backTrack(res, temp, nums, i+1);
            temp.erase(temp.end()-1, temp.end());
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector<vector<int> > result = s.subsets(nums);
}


/*
这道回溯题目做了半个月！！！
还看了答案，生气。

1. 注意还有个空集，第一个函数中不需要有for循环
2. 注意 erase函数的写法， vector.erase(vector.beginErasePositionIteration, vector.endNotErasePositionIteration)

9ms 2.47%
贼慢啊！

这道题的discuss非常有用
mark一个 
https://leetcode.com/problems/subsets/discuss/

*/