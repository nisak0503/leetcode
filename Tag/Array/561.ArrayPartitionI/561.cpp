class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i < nums.size()/2; ++i)
        {
            sum += nums[2*i];
        }
        return sum;
    }
};
/*
Sounds easy, and currently there is no algorithm without sorting

Thanks to GQ, it was a little hard for me to understand the meaning of the problem.

Take (1, 4, 2, 3) for example
sum = (1,2)+(3,4)
because the minimum number in the pair (1, 2) is 1
while (3, 4) is 3
just add 1 + 3 = 4


*/