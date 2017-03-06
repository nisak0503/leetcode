class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        vector<int> res;
        for(int index1 = 0; index1 < len; index1++)
        {
            if(numbers[index1] > target / 2) break;
            int remain = target - numbers[index1];
            for(int index2 = index1+1; index2 < len; index2++)
            {
                if(numbers[index2] > remain) break;
                if(numbers[index2] == remain)
                {
                    res.push_back(index1+1);
                    res.push_back(index2+1);
                    return res;
                }
            }
        }
        return res;
    }
};


/*
beats 6.03% 133ms
beats 31.03% 6ms

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index1 = 0, index2 = numbers.size() - 1;
        while(numbers[index1] + numbers[index2] != target)
        {
            if(numbers[index1] + numbers[index2] < target)
            {
                index1 ++;
            }
            if(numbers[index1] + numbers[index2] > target)
            {
                index2 --;
            }
        }
        vector<int> res;
        res.push_back(index1 + 1);
        res.push_back(index2 + 1);
        return res;
    }
};
 
 
*/