#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream fin("611.in");

class Solution {
public:
  vector<int> nums;
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.begin()+nums.size());
        int k = 2, cnt = 0;
        if(nums.size() < 3) return 0;
        for(int i = 0; i < nums.size()-2; ++i)
        {
            if(nums[i] <= 0) continue;
            for(int j = i+1; j < nums.size()-1; ++j)
            {
                if(nums[j] <= 0) continue;
                int k = j+1;
                while(nums[i] + nums[j] > nums[k])
                {
                    k++;
                    if(k >= nums.size())
                    {
                        break;
                    }
                }
                k--;
                cout << nums[i]<<" + "<<nums[j]<<"> "<<nums[k]<<" +"<<k-j<<endl;
                cnt += max(0, k - j);
            }
        }
        return cnt > 0 ? cnt : 0;
    }

  void input()
  {
    int num;
    while(fin >> num)
    {
      nums.push_back(num);
    }
  }
};


int main()
{
  Solution s;
  s.input();
  cout << s.triangleNumber(s.nums) << endl;
}

/*
自己做没有想出来qwq
好好反省一下
根据宋胖的算法，计算出 larger[i] 表示 比i大的数， 每次计算 max(i-j, j-i) < k < i+j
只要计算 larger(max(i-j), j-i) - larger(i+j) 即可
我的方法是维护一个smaller数组，保证两个数组都是非等号的。
但是这里出现的问题是，2，2，3这种组合会在 2，2时算1次，2，3，2中被算了两次，因为 2>3-1，两个2。等等，这样算下来，晕掉了。。


以上是solution中的思路。
sort之后，每次从j+1开始循环，做了一定的剪枝
232ms, 25.56%

原java代码如下：
public class Solution {
    public int triangleNumber(int[] nums) {
        int count = 0;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; i++) {
            int k = i + 2;
            for (int j = i + 1; j < nums.length - 1 && nums[i] != 0; j++) {
                while (k < nums.length && nums[i] + nums[j] > nums[k])
                    k++;
                count += k - j - 1;
            }
        }
        return count;
    }
}

写第一遍出现的问题是，
3, 82 不拉不拉，算出来nums[k] = 84
紧接着 19, 22 算出来nums[k] 不应该从84开始
*/
