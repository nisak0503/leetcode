/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
private:
    int cal(vector<NestedInteger>& nestedList, int depth)
    {
        int res = 0;
        for(int i = 0; i < nestedList.size(); ++i)
        {
            if(nestedList[i].isInteger())
            {
                res +=  nestedList[i].getInteger() * depth;
            }
            else
            {
                res += cal(nestedList[i].getList(), depth+1);
            }
        }
        return res;
    }
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return cal(nestedList, 1);
    }
};

/*
一次性过的，3ms, 1.31%
时间复杂度是O(n), 其中n是总的元素，
比如[[[[1]]], 2] 包含了4个list和2个元素，n = 6


看看是否有更快的方法
思路完全一样，但是一个简单的写法
0ms, 61.71%

看到for(type xx : yy) 和 A?B:C
 的强大了。。
 瑟瑟发抖。
*/

class Solution {
private:
    int cal(vector<NestedInteger>& nestedList, int depth)
    {
        int res = 0;
        for(NestedInteger son : nestedList)
        {
            res += son.isInteger() ? son.getInteger() * depth : cal(son.getList(), depth+1);
        }
        return res;
    }
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return cal(nestedList, 1);
    }
};