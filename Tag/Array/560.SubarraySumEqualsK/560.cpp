#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>

using namespace std;

ifstream fin("560.in");
class Solution
{
public:
  vector<int> n, m;
  int k;
  int map[200][200];
public:
  Solution()
  {
    int num;
    while(fin >> num)
    {
      n.push_back(num);
    }

    for(int i = 0; i < n.size() - 1; ++i)
    {
      m.push_back(n[i]);
    }
    this->k = n[n.size()-1];
  }

  /*
  Failed, because map is too large


  int cal(vector<int> nums, int k)
  {
    int cnt = 0;
    int len = nums.size();
    //int map[20000][20000] = {0};
    for(int i = 0; i < len; ++i)
    {
      map[i][i] = nums[i];
      for(int j = i+1; j < len; ++j)
      {
        map[i][j] = map[i][j-1] + nums[j];
        if(map[i][j] == k)
        {
          cnt++;
        }
      }
    }
    return cnt;
  }
  */
  int cal1(vector<int> nums, int k)
  {
    int cnt = 0;
    int sumToI[20010];
    int len = nums.size();
    sumToI[0] = 0;
    for(int i = 0; i < len; ++i)
    {
      sumToI[i+1] = sumToI[i] + nums[i];
      for(int j = 0; j <= i; ++j)
      {
        if(sumToI[i+1] - sumToI[j] == k)
        {
          cnt++;
        }
      }
    }
    return cnt;
  }
  /*
  556ms, 9.73%
  Time complexity O(n^2)
  Space complexity O(n)


还有一个别的办法，就是记住一个int sum.
  每次i更新的时候sum = 0, JAVA代码如下。

  public class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.length; start++) {
            int sum=0;
            for (int end = start; end < nums.length; end++) {
                sum+=nums[end];
                if (sum == k)
                    count++;
            }
        }
        return count;
    }
}

Time complexity O(n^2)
Space complexity O(1)


有一个更好的办法是，哈希。JAVA代码如下。
具体思路是，如果有满足条件的sum1，sum2存在，那么 sum2-sum1 = k, 所以sum2出现的时候，
只要count加上 hashmap里面现有的sum2-k的和的数目就好了。然后更新一下sum2的个数。

public class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0, sum = 0;
        HashMap < Integer, Integer > map = new HashMap < > ();
        map.put(0, 1);
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            if (map.containsKey(sum - k))
                count += map.get(sum - k);
            map.put(sum, map.getOrDefault(sum, 0) + 1);
        }
        return count;
    }
}
Time complexity O(n)
Space complexity O(n)
  */
};


int main()
{
  Solution s;

  cout << s.cal1(s.m, s.k) << endl;
  return 0;
}