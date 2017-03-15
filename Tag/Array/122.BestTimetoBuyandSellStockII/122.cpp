class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int len = prices.size();
        int buy = maxInt;
        vector<int> profit(len, 0);
        for(int i = 0; i < len; ++i)
        {
            if(isLocal(i, len, prices))
            {
                if (buy > prices[i])
                {
                    buy = prices[i];
                }
                else if (buy < prices[i])
                {
                    maxPro += prices[i] - buy;
                    buy = maxInt;
                }
            }
        }
        return maxPro;
    }
    
private:
    int maxInt = 2147483647;
    bool isLocal(int index, int len, vector<int>& prices)
    {
        if(((index == 0) || (index == len - 1)) && (len > 1))
        {
            return true;
        }
        else if (len > 2)
        {
            if ((prices[index - 1] - prices[index]) * (prices[index + 1] - prices[index]) >= 0)
            {
                return true;
            }
        }
        return false;
    }
};



/*

9ms 11.06%
This is not good. Although it is a O(n) algorithm


There is very simple solution 
6ms 39.51%

Explanation:
now we try to improve the solution above.
(a[i]-a[i-1])+(a[i-1]-a[i-2])=a[i]-a[i-2] which is the profits created by i and i-2
so we travel from the end of the array and continually calculate the differece of i and i-1,
we only sum those positive profits then the final results is the maximum profits

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int len = prices.size();
        if(len < 2) return 0;
        for(int i = len - 1; i > 0; --i)
        {
            maxP += prices[i] - prices[i-1] > 0 ? prices[i] - prices[i-1] : 0;
        }
        return maxP;
    }
};
*/