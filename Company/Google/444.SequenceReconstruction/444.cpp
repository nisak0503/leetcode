
     class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if(seqs.empty()) return false;
        vector<int> pos(org.size()+1, 0);
        vector<bool> flag(org.size()+1, false);
        for(int i = 0; i < org.size(); ++i)
        {
            pos[org[i]] = i;
        }
        int cnt = org.size()-1;
        bool f = false;
        for(vector<int> seq : seqs)
        {
            if(seq.empty()) continue;
            for(int i = 0; i < seq.size(); ++i)
            {
                f = true;
                if(seq[i] <= 0 || seq[i] > org.size()) return false;
                if(i == 0) continue;
                int pre = seq[i-1];
                int cur = seq[i];
                if(pos[pre] >= pos[cur]) return false;
                if(!flag[pre] && pos[pre] + 1== pos[cur]) 
                {
                    flag[pre] = true;
                    cnt--;
                }
            }
        }
        if(!f) return f;
        return (cnt == 0);
    }
}; 

/*
66ms, 88.61%
注意思考这个问题是 求最小超集
所以紧挨着的顺序要是一样的

*/