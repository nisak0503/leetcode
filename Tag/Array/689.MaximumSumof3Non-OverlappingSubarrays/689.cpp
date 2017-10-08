/*我的写的一个超时的例子, 要挂了啊啊啊啊啊*/

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> subSum;
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i)
       {
            if (i < k)
            {
                sum += nums[i];
                continue;
            }
            
            subSum.push_back(sum);
            sum = sum - nums[i-k]+nums[i];
       }
        subSum.push_back(sum);
        int result = -2147483647;
        vector<int> answer;
        for (int i = 0; i < subSum.size() - 2 * k; ++i)
        {
            for(int j = i + k; j < subSum.size() - k; ++j)
            {
                for(int z = j + k; z < subSum.size(); ++z)
                {
                    if(result < subSum[i] + subSum[j] + subSum[z])
                    {
                        result = subSum[i] + subSum[j] + subSum[z];
                   
                        if(!answer.empty())
                        {
                            answer.pop_back();
                            answer.pop_back();
                            answer.pop_back();    
                        }
                        
                        answer.push_back(i);
                        answer.push_back(j);
                        answer.push_back(z);
                    }
                }
            }
            
        }
        return answer;
    }
};

/*直观的Ad-hoc方法*/
/*
一个直观的想法：
参考了JAVA的想法， 54.24%
算出所有从i 开始的连续k个数的和[i, i+1, ..., i + k-1] 就是我说的sumVec
这里的想法是直接动态规划
针对每一个i
我们需要知道的是 0 - (i-k)之间最大的sumVec的下标
        以及   (i+k) - (sumVec.size()-1) 之间最大的sumVec的下标
很显然
我们用right存储->这个方向的这个数，每次检查right[i-1]作为下标的sumVec是否大于sumVec[i]
存储下标right[i-1]或者i
同理，这里因为vector只能push_back来存储，所以我写的是倒过来存的left
所以left的下标关系为sumVec.size()-1 对应0， sumVec.size()-2 对应1
let[i+k] => left[left.size()-1-i-k]

大概思路就是这样
*/
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int sum = 0;
        vector<int> sumVec;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(i < k)
            {
                sum += nums[i];
                
                continue;
            }
            sumVec.push_back(sum);
            sum = sum - nums[i-k] + nums[i];
        }
        sumVec.push_back(sum);
        
        vector<int> right, left;
        right.push_back(0);
        for(int i = 1; i < sumVec.size(); ++i)
        {
            if(sumVec[right[i-1]] < sumVec[i])
            {
                right.push_back(i);
            }
            else
            {
                right.push_back(right[i-1]);
            }
        }
        left.push_back(sumVec.size()-1);
        for(int j = sumVec.size()-2; j >= 0; --j)
        {
            if(sumVec[left[sumVec.size()-2-j]] < sumVec[j])
            {
                left.push_back(j);
            }
            else
            {
                left.push_back(left[sumVec.size()-2-j]);
            }
        }
       
        int max = -2147483647;
        vector<int> result;
        for(int i = k; i < sumVec.size()-k; ++i)
        {
            int buf = sumVec[right[i-k]] + sumVec[i]+sumVec[left[left.size()-1-i-k]]; 
            if(buf > max)
            {
                max = buf; 
                vector<int> temp;
                temp.push_back(right[i-k]);
                temp.push_back(i);
                temp.push_back(left[left.size()-1-i-k]);
                result = temp;
            }
        }
        return result;
            
        
    }
};


