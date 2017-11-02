class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end()); // small - large
        int j = 0, i = 0;
        int ans = 0;
        while(j < g.size() && i < s.size())
        {
            if(s[i] >= g[j])
            {
                ans++;
                j++;
                i++;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};
/*
56ms, 15.80%
感觉做的不好，sort两次就 O(nlogn)了
两次遍历 m + n

诶，好像大家都是这样做的。。Orz

*/