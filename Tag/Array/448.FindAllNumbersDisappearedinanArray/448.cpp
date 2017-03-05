class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
        {
            int index = abs(*it) - 1;
            nums[index] = nums[index] > 0 ? -nums[index] : nums[index];
        }
        
        vector<int> result;
        for(int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0) result.push_back(i+1);
        }
        return result;
    }
};

/*
 没有做出来
 方法：看题目1-n能否变成角标
 如何标记
 
 其实就是把两个数组（一个原数组，一个标记数组），如何变成一个的思想。
 */