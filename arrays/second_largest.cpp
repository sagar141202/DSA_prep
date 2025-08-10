class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        //your code goes here
    int n = nums.size();

    if(n < 2)
    {
        return -1;
    }

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        if(nums[i] > largest)
        {
            secondLargest = largest;
            largest = nums[i];
        }

        else if(nums[i] > secondLargest && nums[i] < largest)
        {
            secondLargest = nums[i];
        }
    }
    return (secondLargest == INT_MIN) ? -1 : secondLargest;

    }
};