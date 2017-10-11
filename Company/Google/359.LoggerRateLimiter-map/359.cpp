class Logger {
private:
    map<string, int> dict;
public:
    /** Initialize your data structure here. */
    Logger() {
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        
        map<string, int>::iterator it = dict.find(message);
        if(it != dict.end())
        {
           
            if(it->second + 10 <= timestamp)
            {
                dict.erase(it);
                dict.insert(pair<string, int>(message, timestamp));
                return true;
            }
            else
            {
              return false;  
            }
        }
        else
        {
            dict.insert(pair<string, int>(message, timestamp));
            return true;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */




/*
本来一次能过的
第一次wa了
第二次才过
78ms, 47.11%

第一次wa的原因只是这个顺序问题
dict.insert(pair<string, int>(message, timestamp));
dict.erase(it);
蜜汁不清楚。。。
*/