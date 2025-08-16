class Solution {
public:
    int canCapacity(vector<int>& weights, int capacity, int days)
    {
        int countDays = 1;
        int currentLoad = 0;

        for(int w : weights)
        {
            if(currentLoad + w > capacity)
            {
                countDays++;
                currentLoad = 0;
            }
            currentLoad += w;
        }
        return countDays;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
            for (int w : weights) 
            {
                high += w;
            }

        int ans = high;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(canCapacity(weights, mid, days) <= days)
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