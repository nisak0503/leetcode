class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        stack<int> s;
        map<int, int> m;
        for(int num : nums)
        {
            if(s.empty())
            {
                s.push(num);
            }
            else
            {
                while((!s.empty()) &&(num > s.top()))
                {
                    m.insert(pair<int, int>(s.top(), num));
                    s.pop();
                }
                s.push(num);
            }
        }
        while(!s.empty())
        {
            m.insert(pair<int, int>(s.top(), -1));
            s.pop();
        }
        for(int n : findNums)
        {
            res.push_back(m[n]);
        }
        return res;
    }
};

/*
看了一下这道题有点像stack，因为之后出现的一个大数对前面的所有小数都有影响。。所以成功做出来了。。
9ms, 54.33% 感觉还行？

标答解释：因为一直在下降，所以可以用stack
时间空间复杂度都是 O(m + n)
时间复杂度：
nums数组被扫了一次 n
栈的n个数都被弹出一次
findNums数组也被扫了一次 m
所以 （n+m)

空间复杂度：
stack和map都是n大小
res 数组是m大小

*/