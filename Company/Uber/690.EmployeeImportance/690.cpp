/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
private:
    int getSum(vector<Employee*> employees, int id)
    {
        for(Employee* epointer : employees)
        {
            if(epointer -> id == id)
            {
                int result = epointer->importance;
                for(int i : epointer->subordinates)
                {
                    result += getSum(employees, i);
                }
                return result;
            }
        }
        return 0;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        return getSum(employees, id);
    }
};


/*
就是一个很普通的算法。。。
但是非常慢，因为vector<int>每次搜索id都要O(n),O(n) * O(叶子)?
最差是不是就O(n^2)了
26ms, 10.41%

答案的一种方法是直接用unordered_map进行加速
146ms, 0.21%
这加速的什么鬼啊~！！！

用了他本人的代码
26ms, 10.41%
这不科学
*/

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/

/*这是我写的*/
class Solution {
private:
    unordered_map<int, Employee*> dict;
    int getSum(unordered_map<int, Employee*> dict, int id)
    {
        int sum = dict[id] -> importance;
        for(int i : dict[id]->subordinates)
        {
            sum += getSum(dict, i);
        }
        return sum;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        for(Employee* e : employees)
        {
            dict[e->id] = e;
        }
        return getSum(dict, id);
    }
};

/*这是答案写的*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        
        unordered_map<int, Employee*> map;
        
        for(const auto element : employees){
            
            map[element->id] = element;
        }
        
        return help(map, id);
    }
    
    int help(unordered_map<int, Employee*>& map, const int id){
        
        auto sum = map[id]->importance;
        
        for(const auto element : map[id]->subordinates){
            
            sum += help(map, element);
        }
        
        return sum;
    }
};