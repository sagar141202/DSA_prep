class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int candidate = 0;

        for(int num : nums)
        {
            if(count == 0)
            {
                candidate = num;
            }

            if(num == candiddate)
            {
                count++;
            }

            else
            {
                count--;
            }
        }
        return candidate;
    }
};