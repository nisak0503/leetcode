class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        map<int, int> dict;
        int size = candies.size();
        int kinds = 0;
        for(int candy : candies)
        {
            if(dict.find(candy) == dict.end())
            {
                kinds++;
                dict.insert(pair<int, int>(candy, 1));
            }
        }
        return min(kinds, size/2);
    }
};


/*
这道题题目理解让我想了很久

直观上 就是size()/2
但是如果种类不足的话，就是kinds数了

406ms, 9.24%

看答案前我觉得这里用hash比较好
只是把map改成unordered_map就能 
302ms, 53.13%

看了答案之后打开了新世界的大门
有一种东西叫unordered_set

298ms, 58.01%

以及、没看懂bitset的方法，据说击败了99.60%?
*/

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> dict;
        
        for(int candy : candies)
        {
               dict.insert(candy);
            
        }
        return min(dict.size(), candies.size()/2);
    }
};