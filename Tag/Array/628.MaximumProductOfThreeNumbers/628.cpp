class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.begin()+nums.size());
        int max = nums[nums.size()-1] * nums[nums.size()-2] * nums[nums.size()-3];
        if(nums[0] * nums[1] * nums[nums.size()-1] > max)
        {
            max = nums[0] * nums[1] * nums[nums.size()-1];
        }
        return max;
    }
};

/*
72ms, 41.33%

我的思路：先sort一下。因为有负值，要么是最大的三个，要么是最小的两个和最大的一个

这个时间复杂度是 nlogn
空间复杂度是 logn


有一个 时间复杂度 O(n), 空间复杂度O(1)的蠢方法
我们只需要最小的两个和最大的三个

所以只要for循环一遍，把max1, max2, max3存下来，min1, min2存下来即可。
*/