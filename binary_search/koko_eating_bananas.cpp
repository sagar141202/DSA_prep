class Solution {
public:
    bool canEatAll(vector<int>& piles,int speed, int h)
    {
        long long actualHours = 0;

        for(int x : piles)
        {
            actualHours += x / speed;

            if(x % speed != 0)
            {
                actualHours++;
            }
        }
        return actualHours <= h;

    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int answer = high;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(canEatAll(piles, mid, h))
            {
                answer = mid;
                high = mid - 1;
            }
            
            else
            {
                low = mid + 1;
            }
        }
        return answer;
    }
};