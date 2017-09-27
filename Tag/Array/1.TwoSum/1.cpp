class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> res;
        for(int i = 0; i < size; ++i)
        {
            for(int j = i+1; j < size; ++j)
            {
                if(nums[i] + nums[j] == target)
                {
                    res.push_back(i);
                    res.push_back(j);
                }
            }
        }
        return res;
    }
};

/*
209ms
17.86%
时间复杂度 O(n^2)
空间复杂度 O(1)
大概是最慢的方法了吧、囧

本来想二分的，发现下标在sort之后会改变、心塞。

看了下其他的解法，Hash Table. 这个方法我一直不太会用。。

下面学习一下
 
 Approach #2 (Two-pass Hash Table)
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> uomap;
        int size = nums.size();
        vector<int> result;
        int j;
        for(int i = 0; i < size; ++i)
        {
            uomap.insert(pair<int, int>(nums[i], i));
        }
        for(int i = 0; i < size; ++i)
        {
            if((uomap.find(target-nums[i]) != uomap.end()) && ((j = uomap.find(target-nums[i])->second) != i))
            {
                
                if(i < j) swap(i, j);
                result.push_back(j);
                result.push_back(i);
                return result;
            }
        }
    }
};



/*
6ms 80.82%
Very fast!!!
不知道为什么hash_map好像在leetcode里面不被承认，
大概是C++11之后都认为是unordered_map了
这里对每个键值的访问直接是->first, ->second, 简直不要太棒啊！


Approach #3 (One-pass Hash Table)
很直观呀，可以一边加入table，一边计算嘛
直接删掉一个for（合并就好），时间还是一样的，复杂度也是一样的。
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> uomap;
        int size = nums.size();
        vector<int> result;
        int j;
        for(int i = 0; i < size; ++i)
        {
            uomap.insert(pair<int, int>(nums[i], i));
            if((uomap.find(target-nums[i]) != uomap.end()) && ((j = uomap.find(target-nums[i])->second) != i))
            {
                
                if(i < j) swap(i, j);
                result.push_back(j);
                result.push_back(i);
                return result;
            }
        }
    }
};




