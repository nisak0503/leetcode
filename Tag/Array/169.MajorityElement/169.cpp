class Solution {
private:
    int Partition(vector<int>& nums, int low, int high)
    {
        int pivot = nums[high];
        int same = 0;
        while(low < high)
        {
            while(low < high && nums[low] <= pivot)
            {
                if(nums[low] == pivot) same++;
                low ++;
            }
            if(low < high)
            {
                //swap(nums[low], nums[high]);
                //high--;
                nums[high--] = nums[low];
            }
            while(low < high && nums[high] >= pivot)
            {
                if(nums[high] == pivot) same ++;
                high --;
            }
            if(low < high)
            {
                //swap(nums[low], nums[high]);
                //low++;
                nums[low++] = nums[high];
            }

        }
        nums[low] = pivot;
        if(same >= (nums.size() - 1)/2) return low + nums.size();
        return low;
    }
    void QuickSort(vector<int>& nums, int low, int high)
    {
        int length = nums.size();
        int pivotPos;   
        if(low < high)
        {
            pivotPos = Partition(nums, low, high);
            if(pivotPos >= length)
            {
                pivotPos -= length;
                nums[(length-1)/2] = nums[pivotPos];
                return;
            }
            QuickSort(nums, low, pivotPos-1);
            QuickSort(nums, pivotPos+1, high);
        }
    }
public:
    
    int majorityElement(vector<int>& nums) {
        int length = nums.size();
        QuickSort(nums, 0, length - 1);
        return nums[(length-1) / 2];
    }
};


/*
26ms 24.76%

This is so sad

Actually, there is a better and simpler solution



19ms 67.68%
class Solution {

public:
    
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int count = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(count == 0)
            {
                majority = nums[i];
                count++;
            }
            else
            {
                if(majority == nums[i]) count++;
                else count--;
            }
        }
        return majority;
    }
};
*/