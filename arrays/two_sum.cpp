class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            int complement = target - nums[i];

            if(seen.find(complement) != seen.end())
            {
                return {seen[complement], i};
            }

            seen[nums[i]] = i;
        }
        return {};
    }
};