class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int inPoison = 0;
        int len = timeSeries.size();
        for(int timeIndex = 0; timeIndex < len-1; ++timeIndex)
        {
            if(timeSeries[timeIndex] + duration < timeSeries[timeIndex+1])
            {
                inPoison += duration;
            }
            else
            {
                inPoison += timeSeries[timeIndex+1] - timeSeries[timeIndex];
            }
        }
        if(len > 0) inPoison += duration;
        return inPoison;
    }
};

/*
Easy, do it by myself
*/