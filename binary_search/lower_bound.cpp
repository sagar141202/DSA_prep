class Solution{
public:
    int lowerBound(vector<int> &nums, int x){
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(nums[mid] < x)
            {
                low = mid + 1;
            }

            else
            {
                high = mid - 1;
            }
        }

        return low;
    }
};