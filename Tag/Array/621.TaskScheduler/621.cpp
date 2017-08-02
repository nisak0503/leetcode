
class Solution {
public:
    int map[26];
    int leastInterval(vector<char>& tasks, int n) {
        int allsize = tasks.size();
        for(int i = 0; i < allsize; ++i)
        {
              map[tasks[i] - 'A']++;
        }
        int time = 0;
        while(allsize > 0) //可以不要这一层，因为sort之后map[25]是最大的
        {
            sort(map, map+26);
            while(map[25] > 0)
            {
                time++; //maxChar in position
                map[25]--;
                allsize--;
                if(map[25] == 0) break; //防止后面多算，如果不要allsize的while循环，那么要在后面进入一次sort
                for(int i = 1; i <= n; ++i)
                {
                    if((25-i >= 0)&&(map[25-i] > 0))
                    {
                        map[25-i]--;
                        allsize--;
                    }
                    time++;
                } 
                sort(map, map+26); // A6 B1 C1 D1 E1 F1 G1, n = 2的情况下BC都为0,第二次放A时，要sort一下才能到DEFG
            }            
        }
        return time;
    }
};
/*
79ms  48.13%
看了Java的Solution
空间复杂度O(1), 时间复杂度和time一样（除去最外层的while(allsize)之后），都为O(n)

第二种方法是用优先级队列
for(i = 0; i <= n; ++i) 包含最大的
每次弹出最大的
用一个tempArrayList存下来弹出来的数-1
最后把temp压回优先级队列

第三种思路是，找到空闲时间
总时间 = 任务时间 + 空闲时间

最大空闲时间块儿 = (map[25] - 1) * n
因为空闲不会出现在最后一行。
竖着看，对于每一个任务BCDEF... 都有要么占全一列（即map[25]-1，因为最后一行不用算，反正也属于任务时间），要么还有多的空闲时间。
所以 对每个task T, 都有 idleTime -= min(map[25]-1, map[t])。

最后的值 = idleTime > 0 ? idleTime + taskNumber : TaskNumber

【？？？】这里有个疑问，idleTime < 0的时候为什么一定会是TaskNumber？会不会出现新的idleTime呢
贴上Solution的JAVA代码：

public class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] map = new int[26];
        for (char c: tasks)
            map[c - 'A']++;
        Arrays.sort(map);
        int max_val = map[25] - 1, idle_slots = max_val * n;
        for (int i = 24; i >= 0 && map[i] > 0; i--) {
            idle_slots -= Math.min(map[i], max_val);
        }
        return idle_slots > 0 ? idle_slots + tasks.length : tasks.length;
    }
}
*/

/*
一个贪心失败的例子。
A 口 口
A 口 口
A 口 口
A 口 口
A 口 口
-----
A B 口
A B 口
A B 口
A C 口
A D 口
-----
A B C
A B D
A B
A
A
----
显然第二种好啊！！！
是不是傻。


#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class Solution {
    struct element{
      char ch;
      int num;
    } alphabet[26];
    int len;
    int find(char ch)
    {
        for(int i = 0; i <= len; ++i)
        {
            if(alphabet[i].ch == ch)
            {
                return i;
            }
        }
        alphabet[++len].ch = ch;
        return len;
    }
    static bool compare(element e1, element e2)
    {
        return (e1.num > e2.num);
    }
public:
    Solution()
    {
        len = -1;
    }
    int leastInterval(vector<char>& tasks, int n) {
        int allsize = tasks.size();
        for(int i = 0; i < allsize; ++i)
        {
            alphabet[find(tasks[i])].num++;
        }
        int res = 0;
        int charTail = len;
        
        while(allsize > 0)
        {
            sort(alphabet, alphabet + (charTail+1), compare);

            // show alphabet
            for(int i = 0; i <= charTail; ++i)
            {
                cout << alphabet[i].ch <<": "<<alphabet[i].num<<endl;
            }
            cout << "--end--"<<endl;
            res += (alphabet[0].num - 1) * (n + 1) + 1;
            
            for(int i = 0; i < n; ++i)
            {
                if(i+1 > charTail)
                {
                    break;
                }
                
                int place = alphabet[0].num;
                while((i+1 < charTail)&&(place - alphabet[i+1].num >= alphabet[charTail].num))
                {
                    if(place - alphabet[i+1].num == alphabet[charTail].num)
                    {
                        if(i < n - 1)
                        {
                            break;
                        }
                        res++;
                    }
                    allsize -= alphabet[charTail].num;
                    place -= alphabet[charTail].num;
                    alphabet[charTail].num = 0;
                    charTail--;                    
                }
                
                if(alphabet[i+1].num == alphabet[0].num)
                {
                    res++;
                }
                allsize -= alphabet[i+1].num;
                alphabet[i+1].num = 0;
            }
            
            allsize -= alphabet[0].num;
            alphabet[0].num = 0;
        }
        return res;
    }
};
ifstream fin("621.in");
int main()
{
    Solution s;
    vector<char> v;
    char ch;
    bool left = false;
    while(fin >> ch)
    {
        if((ch == '\'') && (left == false))
        {
            left = true;
            fin >> ch;
            v.push_back(ch);
            fin >> ch;
            left = false;
        }
    }
    cout << s.leastInterval(v, 1)<<endl;
}

*/