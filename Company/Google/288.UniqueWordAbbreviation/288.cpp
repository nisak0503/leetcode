class ValidWordAbbr {
private:
    vector<string> innerDict;
    vector<string> dict;
public:
    ValidWordAbbr(vector<string> dictionary) {
        for(string s : dictionary)
        {
            dict.push_back(s);
            int size = s.size();
            if(size >= 3)
            {
                string str = s;
                s = str[0] + to_string(size-2)+ str[size-1];
            }
            innerDict.push_back(s);
        }
    }
    
    bool isUnique(string word) {
        string ss = word;
        int size = word.size();
        if(size >= 3)
        {
            ss = word[0] + to_string(size-2) + word[size-1];
        }
        for(int i = 0; i < dict.size(); ++i)
        {
            if((dict[i].compare(word) != 0) && (innerDict[i].compare(ss) == 0)) return false;
        }
        return true;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */




/*
这个题目有毒，第一次没有创建dict, 然后挂在了
dict = ["hello"]
word = "hello"
上，因为它要求的是和自己不一样的其他的string是否也满足这个简写

726ms, 0.33%
太慢了，其实1.检查是否完全匹配，2.检查长度是否相等 3.首尾两个字母是否相等就可以了

由于时间关系，这里做的非常的暴力，打了个补丁dict, 强制加入比较

直觉上觉得这里 hash比较好，键值是 简写，里面的内容是全部的string
但是hash不能出现键值相同的情况，所以这里【标答】用的<string, unordered_set<stirng>>
这样人为实现了bucket
*/


class ValidWordAbbr {
private:
    unordered_map<string, unordered_set<string>> hash;
public:
    ValidWordAbbr(vector<string> dictionary) {
        for(string s : dictionary)
        {
            string str = s;
            int size = s.size();
            if(size >= 3)
            {
                str = s[0] + to_string(size-2)+ s[size-1];
            }
            hash[str].insert(s);
        }
    }
    
    bool isUnique(string word) {
        string ss = word;
        int size = word.size();
        if(size >= 3)
        {
            ss = word[0] + to_string(size-2) + word[size-1];
        }
        if(hash[ss].count(word) == hash[ss].size())
            return true;
        else
            return false;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */

/*
这个想法：175ms, 22.19%
我理解的 初始化 O(n), isUnique O(1)？ 要看具体内部的实现了
*/
