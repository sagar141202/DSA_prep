class Solution {
public:
    bool canAllocate(vector<int> &nums, int maxPagesAllowed, int m, int n)
    {
        int student = 1;
        int pages = 0;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] > maxPagesAllowed)
            {
                return false;
            }

            if(pages + nums[i] <= maxPagesAllowed)
            {
                pages += nums[i];
            }

            else
            {
                student++;
                pages = nums[i];
            }
        }
        
        if(student <= m)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int findPages(vector<int> &nums, int m)  {
        int n = nums.size();
        int low = 0; 
        int high = 0;
        int ans = high;

        for(int i = 0; i < n; i++)
        {
            high += nums[i];
        }

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(canAllocate(nums, mid, m, n))
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