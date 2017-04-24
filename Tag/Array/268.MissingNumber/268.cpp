class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int length = nums.size();
        int total = length * (length + 1) / 2;
        int sum = 0;
        for(int i = 0; i < length; ++i)
        {
            sum += nums[i];
        }
        return total - sum;
    }
};

/*
32ms, 31.00% really easy
*/