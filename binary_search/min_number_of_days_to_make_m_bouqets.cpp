class Solution {
public:
    int canMakeAll(vector<int>& bloomDay, int midDay, int k)
    {
        int bouquetCount = 0;
        int consequetiveCount = 0;

        for(int i = 0; i < bloomDay.size(); i++)
        {
            if(bloomDay[i] <= midDay)
            {
                consequetiveCount++;
            }
            else
            {
                consequetiveCount = 0;
            }

            if(consequetiveCount == k)
            {
                bouquetCount++;
                consequetiveCount = 0;
            }
        }
        return bouquetCount;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int firstDay = 0;
        int lastDay = *max_element(bloomDay.begin(), bloomDay.end());
        int minDay = -1;

        while(firstDay <= lastDay)
        {
            int midDay = firstDay + (lastDay - firstDay) / 2;

            if(canMakeAll(bloomDay, midDay, k) >= m)
            {
                minDay = midDay;
                lastDay = midDay - 1;
            }

            else
            {
                firstDay = midDay + 1;
            }
        }
        return minDay;
    }
};