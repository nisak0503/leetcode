class MovingAverage {
private:
    int count;
    vector<int> numbers;
    double sum = 0;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        count = size;
    }
    
    double next(int val) {
        
        numbers.push_back(val);

        int length = numbers.size();
        if(length <= count)
        {
            sum += val;
            return sum / length;
        }
        else
        {
            sum = sum - numbers[length - count - 1] + numbers[length - 1];
            return sum / count;
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */



/*
32ms, 75.04%
这个不错~ 一次性过的
*/