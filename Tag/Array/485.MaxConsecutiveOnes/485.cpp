class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxConsecutive = 0;
        int consecutive = 0;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
        {
            if(*it & 1)
            {
                maxConsecutive = max(maxConsecutive, ++consecutive);
            }
            else
            {
                consecutive = 0;
            }
            
        }
        return maxConsecutive;
    }
};


/*
Hunter's algorithm

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxConsecutive = 0;
        int consecutive = 0;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
        {
            if(*it & 1)
            {
                consecutive++;
            }
            else
            {
                maxConsecutive = max(maxConsecutive, consecutive);
                consecutive = 0;
            }
            
        }
        maxConsecutive = max(maxConsecutive, consecutive);
        return maxConsecutive;
    }
};

*/