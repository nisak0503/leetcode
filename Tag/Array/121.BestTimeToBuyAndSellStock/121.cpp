class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int low;
        if(prices.size() > 0) low = prices[0];
        for(int i = 0; i < prices.size(); ++i)
        {
            if(prices[i] < low) low = prices[i];
            if(prices[i] > low) profit = max(prices[i] - low, profit);
        }
        return profit;
    }
};

/*
6ms 37.78%
之前面试题哒。
谢谢GU的教授，过几天该写感谢信了。。。
*/