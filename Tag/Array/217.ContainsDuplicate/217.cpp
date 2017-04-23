class Solution {
private:
    int Partition(vector<int>& nums, int low, int high)
    {
        int pivot = nums[low];
        while(low < high)    
        {
            while(low < high && nums[high] >= pivot)
            {
                if(nums[high] == pivot) return -1;
                high--;
            }
            if(low < high)
            {
                nums[low++] = nums[high];
            }
            while(low < high && nums[low] <= pivot)
            {
                if(nums[low] == pivot) return -1;
                low++;
            }
            if(low < high)
            {
                nums[high--] = nums[low];
            }
        }
        nums[low] = pivot;
        return low;
    }
    
    bool dupFlag = false;
    
    void QuickSort(vector<int>& nums, int low, int high)
    {
        int pivotPos;
        if(low < high)
        {
            pivotPos = Partition(nums, low, high);
            if(pivotPos == -1) 
            {
                dupFlag = true;
                return;
            }
            QuickSort(nums, low, pivotPos-1);
            QuickSort(nums, pivotPos+1, high);
        }
    }
public:

    /*bool containsDuplicate(vector<int>& nums) {
        dupFlag = false;
        int length = nums.size();
        QuickSort(nums, 0, length-1);
        return dupFlag;
    }*/
    bool containsDuplicate(vector<int> & nums)
    {
        sort(nums.begin(), nums.end());
        int length = nums.size();
        if(length < 2) return false;
        for(int i = 0; i < length-1; ++i)
        {
            if(nums[i] == nums[i+1]) return true;
        }
        return false;
    }
};


/*
I just use sort in vector!
36ms 63.20%


BUT! MY QS is TLE!
why???

According to wereFlute
Sort will accommendate if the sort depth is too big
it will change to heep sort 堆排序
自适应算法，平时是快排，一定深度后会变成堆排序
可怕！
*/