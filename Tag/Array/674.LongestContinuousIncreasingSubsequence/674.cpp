class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() < 1) 
        {
            return 0;
        }
        int ans = 1, temp = 1;
        int pre = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] > pre)
            {
                temp++;
                pre = nums[i];
            }
            else
            {
                ans = max(ans, temp);
                pre = nums[i];
                temp = 1;
            }
        }
        ans = max(ans, temp);
        return ans;
    }
};

/*
16ms 22.41%
比想象中的击败的成绩要少呀

这里注意24行的ans = max(ans, temp)是一定要的，因为很有可能这个vector中所有数都递增
注意极端情况的检查

看一下别人做的，好像思路差不多
*/
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 0, cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0 || nums[i-1] < nums[i]) res = max(res, ++cnt);
            else cnt = 1;
        }
        return res;
    }

/*
下面是有人用JAVA写的DP！
其实就是把cnt给存下来了。。。。
*/

class Solution {
    public int findLengthOfLCIS(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int n = nums.length;
        int[] dp = new int[n];
        
        int max = 1;
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
            else {
                dp[i] = 1;
            }
            max = Math.max(max, dp[i]);
        }
        
        return max;
    }
}
