class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxSum = nums[0];
        int pre = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            
            if(sum < nums[i])
            {
                sum = nums[i];
            }
            maxSum = max(sum, maxSum);        
        
        }
        return max(maxSum, sum);   
    }
};

/*
12ms, 22.79%
这个问题遇到了好几遍了

一定是有O(N)的解法的，这次也错了好几遍， corner case没有处理清楚
每次和自己比较 如果小的话说明前面的不必要


答案中更直观的想法是
一直加下去，直到sum小于0就不算了，变成0重新加

9ms, 43.70%
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxSum = nums[0];
        for(int n : nums)
        {
            sum += n;
            maxSum = max(sum, maxSum);
            sum = max(sum, 0);
        }
        return maxSum;
    }
};






