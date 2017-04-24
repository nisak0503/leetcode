class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[abs(nums[i])-1] < 0) return abs(nums[i]);
            else
            {
                nums[abs(nums[i])-1] *= -1;
            }
        }
    }
};

/*
16ms, 18.66%
Just use the flip function hhhh

方法二：指针跑圈
<https://leetcode.com/problems/find-the-duplicate-number/#/solutions>

*/
