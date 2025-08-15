class Solution {
public:
    long long floorSqrt(long long n)  {
        if(n == 0 || n == 1)
        {
            return n;
        }

        long long low = 1;
        long long high = n / 2;
        int ans = 1;

        while(low <= high)
        {
            long long mid = low + (high - low) / 2;

            int sq = mid * mid;

            if(sq == n)
            {
                return mid;
            }

            else if(sq < n)
            {
                ans = mid;
                low = mid + 1;
            }

            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};