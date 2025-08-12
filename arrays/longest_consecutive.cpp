class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> s(nums.begin(), nums.end()); // Step 1: store all numbers
        int longest = 0;

        // Step 2: Loop through each number
        for (int num : nums) {
            // Only start counting if it's the beginning of a sequence
            if (s.find(num - 1) == s.end()) {
                int currentNum = num;
                int count = 1;

                // Step 3: Count consecutive numbers
                while (s.find(currentNum + 1) != s.end()) {
                    currentNum++;
                    count++;
                }

                // Step 4: Update longest length
                longest = max(longest, count);
            }
        }

        return longest;
    }
};
