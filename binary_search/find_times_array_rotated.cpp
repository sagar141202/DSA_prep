class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(nums[low] <= nums[high])
            {
                return low;
            }

            int prev = (mid + n - 1) % n;
            int next = (mid + 1) % n;

            if(nums[mid] <= nums[prev] && nums[mid] <= nums[next])
            {
                return mid;
            }

            else if(nums[low] <= nums[mid])
            {
                low = mid + 1;
            }

            else
            {
                high = mid - 1;
            }
        }
        return 0;
    }
};