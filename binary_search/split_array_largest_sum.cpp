class Solution {
public:
    bool maxLar(vector<int> &nums, int maxSumAllowed, int k, int n)
    {
        int currentSum = 0;
        int subarray = 1;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] > maxSumAllowed)
            {
                return false;
            }

            if(currentSum + nums[i] <= maxSumAllowed)
            {
                currentSum += nums[i];
            }

            else
            {
                subarray++;
                currentSum = nums[i];
            }
        }

        return subarray <= k;
    }

    int splitArray(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int low = 0;
        int high = 0;

        for(int i = 0; i < n; i++)
        {
            high += nums[i];
        }

        int ans = high;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(maxLar(nums, mid, k, n))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }   
};