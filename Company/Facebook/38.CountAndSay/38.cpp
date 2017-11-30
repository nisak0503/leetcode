class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string lastAns = countAndSay(n-1);
        string ans = "";
        int cnt = 1;
        char last = lastAns[0];
        int index = 1;
        while(index < lastAns.size())
        {
            if(lastAns[index] == last)
            {
                cnt++;
            }
            else
            {
                ans.append(to_string(cnt));
                ans+=last;
                cnt = 1;
                last = lastAns[index];
            }
            index++;
        }
        ans.append(to_string(cnt));
        ans +=last;
        return ans;    
    }
};

/*
3ms, 23.28%
读懂题目就好了。。
一个递归
或者一个循环更加能节约时间吧, 跑起来的时候并没有，还是3ms, 23.28%。。。
*/

class Solution {
public:
    string countAndSay(int n) {      
        
        if(n == 1) return "1";
        string lastAns = "1";
        string ans = "";
        for(int i = 2; i <= n; ++i){
            ans = "";
            int cnt = 1;
            int index = 1;
            char last = lastAns[0];
            while(index < lastAns.size())
            {
                if(lastAns[index] == last)
                {
                    cnt++;
                }
                else
                {
                    ans += (to_string(cnt)) + last;
                    cnt = 1;
                    last = lastAns[index];
                }
                index++;
            }
            ans += (to_string(cnt)) + last;
            lastAns = ans;
        }
        return ans;    
    }
};