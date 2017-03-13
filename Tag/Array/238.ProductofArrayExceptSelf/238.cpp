class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int product2 = 1;
        int len = nums.size();
        int zero = 0;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
        {
            if(*it == 0) 
            {
                zero++;
                if(zero == 1)
                {
                    product2 = product;
                }
            }
            else
            {
                product2 *= *it;
            }
            product *= *it;
        }
        vector<int> res;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
        {
            if(*it == 0) 
            {
                if(zero > 1)
                {
                    res.push_back(0);
                }    
                else
                {
                    res.push_back(product2);
                }
            }
            else
            {
                res.push_back(product / *it);    
            }
            
        }
        return res;
    }
};

/*
89ms 3.55%
This is not good.


49ms 72.88% 
This one looks pretty nice.

Mindset:
First, consider O(n) time and O(n) space solution.

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> fromBegin(n);
        fromBegin[0]=1;
        vector<int> fromLast(n);
        fromLast[0]=1;
        
        for(int i=1;i<n;i++){
            fromBegin[i]=fromBegin[i-1]*nums[i-1];
            fromLast[i]=fromLast[i-1]*nums[n-i];
        }
        
        vector<int> res(n);
        for(int i=0;i<n;i++){
            res[i]=fromBegin[i]*fromLast[n-1-i];
        }
        return res;
    }
};




class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int fromBegin = 1, fromEnd = 1;
        int n = nums.size();
        vector<int> res(n, 1);
        for(int i = 0; i < n; ++i)
        {
            res[i] *= fromBegin;
            fromBegin *= nums[i];
            res[n-1-i] *= fromEnd;
            fromEnd *= nums[n-1-i];
        }
        return res;
    }
};
*/