class Solution {
private:
    queue<pair<string, int>> que;
    bool diff1(string a, string b)
    {
        int cnt = 0;
        for(int i = 0; i < a.size(); ++i)
        {
            if(a[i] != b[i]) cnt++;
        }
        return (cnt == 1);
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        que.push(pair<string, int>(beginWord, 1));
        vector<bool> flag;
        for(int i = 0; i < wordList.size(); ++i)
        {
            flag.push_back(false);
        }
        
        while(!que.empty())
        {
            pair<string, int> begin = que.front();
            que.pop();
            string beginWord = begin.first;
            int step = begin.second;
            
            if(beginWord.compare(endWord) == 0) return step;
            for(int i = 0; i < wordList.size(); ++i)
            {
                if(flag[i]) continue;
                if(diff1(beginWord, wordList[i]))
                {
                    que.push(pair<string, int>(wordList[i], step+1));
                    flag[i] = true;
                }
            }
        }
        return 0;
    }
};


/*
683ms, 15.06%
一个bfs
双向BFS比较厉害
标答的wordList是unordered_set, 可做参考
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        unordered_set<string> head, tail, *phead, *ptail;
        head.insert(beginWord);
        tail.insert(endWord);
        int dist = 2;
        while (!head.empty() && !tail.empty()) {
            if (head.size() < tail.size()) {
                phead = &head;
                ptail = &tail;
            }
            else {
                phead = &tail; 
                ptail = &head;
            }
            unordered_set<string> temp; 
            for (auto itr = phead -> begin(); itr != phead -> end(); itr++) {
                string word = *itr;
                wordDict.erase(word);
                for (int p = 0; p < (int)word.length(); p++) {
                    char letter = word[p];
                    for (int k = 0; k < 26; k++) {
                        word[p] = 'a' + k;
                        if (ptail -> find(word) != ptail -> end())
                            return dist;
                        if (wordDict.find(word) != wordDict.end()) {
                            temp.insert(word);
                            wordDict.erase(word);
                        }
                    }
                    word[p] = letter;
                }
            }
            dist++;
            swap(*phead, temp);
        }
        return 0; 
    }
};