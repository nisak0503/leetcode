class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result;
        int maxNum = k + 1;
        int minNum = 1;
        while(minNum <= maxNum)
        {
            result.push_back(minNum);
            minNum++;
            if(minNum > maxNum) 
            {
                break;
            }
            result.push_back(maxNum);
            maxNum--;
        }
        for(int i = k+1+1; i <= n; ++i)
        {
            result.push_back(i);
        }
        return result;
    }
    
   
};


/*
太晚了可能思路不清WA了好几次，规律还是很好找的，没难度。
29ms 32.44%

答案的思路应该也是类似的。看看JAVA版本
只是他们是 1， 2， 3， ..., n-k-1, (n-k), n, (n-k+1), n-1, ...
注意这个式子特别好
*/
class Solution {
    public int[] constructArray(int n, int k) {
        int[] ans = new int[n];
        int c = 0;
        for (int v = 1; v < n-k; v++) {
            ans[c++] = v;
        }
        for (int i = 0; i <= k; i++) {
            ans[c++] = (i%2 == 0) ? (n-k + i/2) : (n - i/2);
        }
        return ans;
    }
}