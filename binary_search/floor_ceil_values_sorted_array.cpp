class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int floorValue = -1;
        int ceilValue = -1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(nums[mid] == x)
            {
                return {nums[mid], nums[mid]};
            }

            else if(nums[mid] < x)
            {
                floorValue = nums[mid];
                low = mid + 1;
            }

            else{
                ceilValue = nums[mid];
                high = mid - 1;
            }
        }

        return {floorValue, ceilValue};
    }
};