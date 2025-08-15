class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            int prev = mid - 1;
            int next = mid + 1;

            if((mid == 0 || nums[mid] > nums[prev]) && (mid == n - 1 ||nums[mid] > nums[next]))
            {
                return mid;
            }

            else if((mid > 0 && nums[mid - 1] > nums[mid]))
            {
                high = mid - 1;
            }

            else
            {
                low = mid + 1;
            }
        }
        return -1;
    }
};