class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        int n = nums.size();
        int maxFromRight = INT_MIN;
        vector<int> result;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] >= maxFromRight) {
                result.push_back(nums[i]);
                maxFromRight = nums[i];
            }
        }

        // Reverse result to restore original order
        reverse(result.begin(), result.end());

        return result;
    }
};
