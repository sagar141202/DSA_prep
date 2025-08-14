class Solution{
public:
    int upperBound(vector<int> &nums, int x){
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = n; // default to end

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(nums[mid] > x)  // first element greater than x
            {
                ans = mid;
                high = mid - 1; // search left
            }
            else
            {
                low = mid + 1;  // search right
            }
        }
        return ans;
    }
};
