class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;
        int former = nums[0], ans = nums.size();
        
        int i = 0;
        while(i < nums.size()-1)
        {
            i++;
            if(nums[i] == former)
            {
                ans--;
                former = nums[i];
                nums.erase(nums.begin()+i);
                i--;
                continue;
            }
            former = nums[i];
        }
        return ans;
    }
};

/*
49ms, 8.76%
注意 17行的i--; 删掉之后i指向的就没了，应该--;


一个更加简洁的想法，维护两个指针，快的不等于慢的时，拷贝过来即可
23ms, 98.37%
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int slow = 0;
        for(int fast = 1; fast < nums.size(); ++fast)
        {
            if(nums[fast] != nums[slow])
            {
                nums[++slow] = nums[fast];
            }
        }
        return slow+1;
    }
};