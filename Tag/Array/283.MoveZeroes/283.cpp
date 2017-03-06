class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int zero = 0, one = 0;
        while(zero < len && one < len)
        {
            zero = findFirstIndex(true, zero, len, nums);
            one = findFirstIndex(false, zero, len, nums);
            if(zero < len && one < len)
            {
                swap(nums[zero], nums[one]);
                zero++;
            }
        }
    }
    
private:
    int findFirstIndex(bool isZero, int afterIndex, int len, vector<int>& nums)
    {
        for(int i = afterIndex; i < len; ++i)
        {
            if((isZero)&&(nums[i] == 0) || (!isZero) && (nums[i] != 0))
            {
                return i;
            }
        }
        return len;
    }
};

/*
mine: beats 11.68%, 26ms

theirs: beats 47.94%, 16ms


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int j = 0;
        for(int i = 0; i < len; ++i)
        {
            if(nums[i] != 0)
            {
                nums[j++] = nums[i];
            }
        }
        for(; j < len; ++j)
        {
            nums[j] = 0;
        }
    }
};
*/