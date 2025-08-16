class Solution {
public:
    bool smallDivisor(vector<int>& nums, int mid, int threshold)
    {
        int sum = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            sum += (nums[i] + mid - 1) / mid;
        }

        if(sum <= threshold)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int result;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(smallDivisor(nums, mid, threshold) == true)
            {
                result = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return result;
    }
};