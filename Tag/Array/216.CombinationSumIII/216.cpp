class Solution {

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> answer;
        vector<vector<int>> answerSet;
        if(k < 1 || n < 1 || k < n) return answerSet;
        
        if(k == 1 && n <= 9 && n >= 1)
        {
            answer.push_back(n);
            answerSet.push_back(answer);
            return answerSet;
        }
        for(int i = 1; i <= 9; ++i)
        {
            vector<vector<int>> f = combinationSum3(k-1, n-i);
            for(int j = 0; j < f.size(); ++j)
            {
                if(i <= f[j][f[j].size()-1]) continue;
                vector<int>::iterator it = f[j].find(i);
                if(it == f[j].end())
                {
                    f[j].push_back(i);
                    answerSet.push_back(f[j]);
                }
            }
        }
        return answerSet;
    }
};


/*
39ms, 0.22%
递归的方式 特别慢，最后一个点 k = 9, n = 45， 暴力过的

3ms   3.31%


class Solution {

private:
    void combination(vector<vector<int>>& answerSet, vector<int> answer, int k, int n)
    {
        if(k == answer.size() && n == 0)
        {
            answerSet.push_back(answer);
            return;
        }
        if(answer.size() < k)
        {
            for(int i = answer.empty() ? 1 : answer.back()+1; i <= 9; ++i)
            {
                if(n - i < 0) break;
            
                answer.push_back(i);
                combination(answerSet, answer, k, n-i); //第k个
                answer.pop_back();
            }    
        }
        
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> answer;
        vector<vector<int>> answerSet;
        combination(answerSet, answer, k, n);
        return answerSet;
    }
};

*/