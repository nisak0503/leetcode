class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
        {
            int index = abs(*it) - 1;
            if(nums[index] < 0) result.push_back(index+1);
            else
                nums[index] = -nums[index];
        }
        return result;
    }
};


/*
Easy，same with Prob 448
*/