class Solution {
public:
    
    int calPoints(vector<string>& ops) {
        stack<int> mystack;
        for(string in : ops)
        {
            if (in == "+")
            { 
                    int i = mystack.top();
                    mystack.pop();
                    int j = mystack.top();
                    mystack.pop();
                    mystack.push(j);
                    mystack.push(i);
                    mystack.push(i+j);
                    continue;
            }
            if(in == "C")
            {
                    mystack.pop();    
                    continue;
            }
            if(in == "D")
            {
                    int k = mystack.top();
                    mystack.push(2 * k);
                    continue;
            }
            mystack.push(stoi(in));
            
            
        }
        int sum = 0;
        while(!mystack.empty())
        {
            sum += mystack.top();
            mystack.pop();
        }
        return sum;
    }
};

/*
6ms, 13.66%

看了一下别人用vector做的，还慢一些
9ms, 4.03%
*/
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum = 0, score = 0;
        vector<int> rounds;
        for (string op : ops) {
            if (op == "C") {
                sum -= rounds.back();
                rounds.pop_back();
                continue;
            }
            if (op == "D") {
                sum += score = rounds.back() * 2;
            }
            else if (op == "+") {
                sum += score = rounds[rounds.size() - 1] + rounds[rounds.size() - 2];
            }
            else {
                sum += score = stoi(op);
            }
            rounds.push_back(score);
        }
        return sum;
    }
};