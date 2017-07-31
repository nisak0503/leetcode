class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int originr = nums.size();
        int originc = nums[0].size();
        if(originr * originc != r * c) 
        {
            return nums; 
        }
        else
        {
            return subReshapeMatrix(nums, originr, originc, r, c);
        } 
    }
    vector<vector<int>> subReshapeMatrix(vector<vector<int>>& nums, int originr, int originc, int r, int c)
    {
        vector<vector<int>> newNums;
        vector<int> blank;
        for(int i = 0; i < r; ++i)
        {
            newNums.push_back(blank);
            for(int j = 0; j < c; ++j)
            {
                newNums[i].push_back(nums[(i*c+j)/originc][(i*c+j) % originc]);
            }
        }
        return newNums;
    }
};

/*
49ms 19.00%
非常简单的一道题
好久没做了，没看清是函数返回二维vector即可。第一遍还仔细cout了一下、有毒。
然后注意坐标的转换，就可以啦。
*/






//Just testing the nums.size() and nums[0].size()
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	vector< vector<int> > nums;
	vector<int> numset, hello;
	numset.push_back(1);
	numset.push_back(2);
	numset.push_back(3);
	hello.push_back(3);
	hello.push_back(4);
	hello.push_back(5);
	nums.push_back(numset);
	nums.push_back(hello);
	cout << nums.size();
	cout << endl << nums[0].size()<<endl;
	return 0;
}
